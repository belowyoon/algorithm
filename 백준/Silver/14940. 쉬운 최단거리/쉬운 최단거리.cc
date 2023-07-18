#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int x, y;
vector<vector<int>> map;
vector<vector<int>> result;
vector<vector<bool>> visited;

int bfs() {
    queue<pair<int,int>> q;
    visited.assign(n,vector<bool>(m,false));
    q.push(make_pair(x,y));
    visited[x][y] = true;
    result[x][y] = 0;
    int cnt = 0;
    while (!q.empty())
    {
        pair<int,int> k = q.front();
        q.pop();
        int i = k.first;
        int j = k.second;
        if (map[i][j] == 0) {
            result[i][j] = 0;
        } 
        else {
            if (i-1 >= 0) {
                if (!visited[i-1][j]) {
                    q.push(make_pair(i-1,j));
                    visited[i-1][j] = true;
                    result[i-1][j] = result[i][j] + 1;
                }
            }
            if (i+1 < n) {
                if (!visited[i+1][j]) {
                    q.push(make_pair(i+1,j));
                    visited[i+1][j] = true;
                    result[i+1][j] = result[i][j] + 1;
                }
            }
            if (j-1 >= 0) {
                if (!visited[i][j-1]) {
                    q.push(make_pair(i,j-1));
                    visited[i][j-1] = true;
                    result[i][j-1] = result[i][j] + 1;
                }
            }
            if (j+1 < m) {
                if (!visited[i][j+1]) {
                    q.push(make_pair(i,j+1));
                    visited[i][j+1] = true;
                    result[i][j+1] = result[i][j] + 1;
                }
            }
            
        }
    }
    return 0;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    cin >> n >> m;
    map.assign(n,vector<int>(m,0));
    result.assign(n,vector<int>(m,0));

    int t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> t;
            if (t == 2) {
                x = i;
                y = j;
            }
            map[i][j] = t;
        }
    }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1 && visited[i][j] == false) {
                cout << -1 << " ";
            } else {
                cout << result[i][j] << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}