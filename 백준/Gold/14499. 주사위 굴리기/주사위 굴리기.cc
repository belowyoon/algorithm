#include <iostream>
#include <algorithm>
using namespace std;

int dice[6];
int direction[2][4] = {
    {0,2,5,3},
    {0,4,5,1}
};

void moveDice(int dir) {
    int d = 1, k = 0, index = 1, prev = dice[0], temp;
    if (dir > 2) {
        k = 1;
    }
    if (dir == 2 || dir == 3) {
        d = -1;
        index = 3;
    }
    for (int i = 0; i < 4; i++) {
        temp = dice[direction[k][index]];
        dice[direction[k][index]] = prev;
        prev = temp;
        index = (index + 4 + d) % 4;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;
    vector<vector<int>> map;
    map.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    
    int dir;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    for (int i = 0; i < k; i++) {
        cin >> dir;
        x += dx[dir-1];
        y += dy[dir-1];
        if (x < 0 || x >= n || y < 0 || y >= m) {
            x -= dx[dir-1];
            y -= dy[dir-1];
        } else {
            moveDice(dir);
            if (map[x][y] != 0) {
                dice[5] = map[x][y];
                map[x][y] = 0;
            } else {
                map[x][y] = dice[5];
            }
            cout << dice[0] << '\n';
        }
    }
    return 0;
}