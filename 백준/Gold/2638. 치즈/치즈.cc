#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
vector<vector<int>> map;
queue<pair<int, int>> q;
int dx[4] = {0, 1, 0 , -1};
int dy[4] = {1, 0, -1, 0};

void checkOutside() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (map[x][y] == -1) continue;
        map[x][y] = -1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (map[nx][ny] == 0){
                q.push({nx,ny});
            }
        }
    }

}

void checkCheese(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    if (map[i+dx[k]][j+dy[k]] == -1) {
                        cnt++;
                    }
                    if (cnt >= 2) {
                        q.push({i,j});
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    cin >> n >> m;
    map.assign(n, vector<int>(m,0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    
    int res = 0;
    q.push({0,0});

    while(!q.empty()){
        checkOutside();
        checkCheese();
        res++;
    }
    cout << res - 1;
    return 0;
}