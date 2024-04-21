#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<vector<char>> map;
vector<vector<bool>> visited;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, char c1, char c2) {
    visited[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
        if (map[nx][ny] == c1 || map[nx][ny] == c2) dfs(nx, ny, c1, c2);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    map.assign(n, vector<char>(n, 0));
    visited.assign(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                dfs(i, j, map[i][j], map[i][j]);
                cnt++;
            }
        }
    }
    cout << cnt << " ";
    cnt = 0;
    visited.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                if (map[i][j] == 'B') dfs(i, j, map[i][j], map[i][j]);
                else dfs(i, j, 'R', 'G');
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
