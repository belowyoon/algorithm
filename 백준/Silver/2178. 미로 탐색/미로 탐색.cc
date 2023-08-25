#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n, m;
    char t;
    cin >> n >> m;

    vector<vector<bool>> map;
    vector<vector<int>> result;
    map.assign(n, vector<bool>(m, false));
    result.assign(n, vector<int>(m,0));
    queue<pair<int,int>> q;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            cin >> t;
            if (t == '1'){
                map[i][j] = true;
            }
        }
    }

    q.push({0,0});
    int x, y, depth = 0;
    while (!q.empty()) {
        int size = q.size();
        depth++;
        for (int i = 0; i < size; i++) {
            pair<int, int> temp = q.front();
            x = temp.first;
            y = temp.second;
            q.pop();
            if (x < 0 || x >= n || y < 0 || y >= m) {
                continue;
            }
            if (!map[x][y]) {
                continue;
            }
            map[x][y] = false;
            result[x][y] = depth;
            for (int j = 0; j < 4; j++) {
                q.push({x+dx[j], y+dy[j]});
            }
        }
    }

    cout << result[n-1][m-1];

    return 0;
}
