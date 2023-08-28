#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<bool>> visited;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int result = 0;

void dfs(int x, int y, int depth, int sum) {

    if (depth == 4) {
        result = max(result, sum);
        return;
    }
    sum += map[x][y];
    depth++;
    if (depth == 2) {
        int t1, t2;
        for (int i = 0; i < 4; i++) {
            int temp = 0;
            t1 = x + dx[i];
            t2 = y + dy[i];
            if (t1 < 0 || t1 >= n || t2 < 0 || t2 >= m) {
                continue;
            }
            if (visited[t1][t2]) {
                if (i < 2) {
                    t2--;
                    if (t2 < 0 || t2 >= m) {
                        continue;
                    }
                    temp += map[t1][t2];
                    t2 += 2;
                    if (t2 < 0 || t2 >= m) {
                        continue;
                    }
                    temp += map[t1][t2]; 
                } else {
                    t1--;
                    if (t1 < 0 || t1 >= n) {
                        continue;
                    }
                    temp += map[t1][t2];
                    t1 += 2;
                    if (t1 < 0 || t1 >= n) {
                        continue;
                    }
                    temp += map[t1][t2]; 
                }
            }
            result = max(result, sum + temp);
        }
    }
    for (int i = 0; i < 4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            continue;
        }
        if (visited[nx][ny]) {
            continue;
        }
        visited[nx][ny] = true;
        dfs(nx, ny, depth, sum);
        visited[nx][ny] = false;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n >> m;
    map.assign(n, vector<int>(m,0));
    visited.assign(n, vector<bool>(m,0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = true;
            dfs(i,j,0, 0);
            visited[i][j] = false;
        }
    }
    cout << result;
    return 0;
}