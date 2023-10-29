#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int cnt = 0;
//북, 동, 남, 서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> room;

void clean(int r, int c, int d) {
    
    if (room[r][c] == 0) {
        room[r][c] = 2;
        cnt++;
    }
    bool flag = false;
    for (int i = 0; i < 4; i++) {
        d = d - 1;
        if (d == -1)
            d = 3;
        int nr = dx[d] + r;
        int nc = dy[d] + c;
        if (room[nr][nc] == 0) {
            flag = true;
            clean(nr, nc, d);
            break;
        }
    }
    if (!flag) {
        int nr = dx[d] * -1 + r;
        int nc = dy[d] * -1 + c;
        if (room[nr][nc] != 1) {
            clean(nr, nc, d);
        }
        else {
            return;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int r, c, d;
    cin >> n >> m >> r >> c >> d;
    room.assign(n,vector<int>(m,0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }
    clean(r,c,d);
    cout << cnt;
    return 0;
}