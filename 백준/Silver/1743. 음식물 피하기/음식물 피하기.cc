#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<bool>> map;
vector<vector<bool>> visited;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cnt = 0;

bool dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    if (visited[x][y]) {
        return false;
    }
    visited[x][y] = true;
    if (!map[x][y]) {
        return false;
    } 
    for (int i = 0; i < 4; i++) {
        dfs(x + dx[i], y + dy[i]);
    }
    cnt++;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int k;
    cin >> n >> m >> k;
    map.assign(n, vector<bool>(m, false));
    visited.assign(n, vector<bool>(m, false));

    int t1, t2;
    for (int i = 0; i < k; i++) {
        cin >> t1 >> t2;
        map[t1-1][t2-1] = true;
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] && !visited[i][j]) {
                dfs(i, j);
                result = max(result, cnt);
                cnt = 0;
            }
        }
    }
    cout << result;
    return 0; 
}