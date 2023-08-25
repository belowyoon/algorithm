#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, v;
vector<vector<int>> map;
vector<bool> visited;

void dfs(int x) {
    if (visited[x]) {
        return;
    }
    cout << x << " ";
    visited[x] = true;
    for(int i = 0; i < map[x].size(); i++) {
        dfs(map[x][i]);
    }
    return;
}

int main () 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n >> m >> v;
    map.assign(n + 1,vector<int>());
    visited.assign(n+1, false);
    
    int t1, t2;
    for(int i = 0; i < m; i++) {
        cin >> t1 >> t2;
        map[t1].push_back(t2);
        map[t2].push_back(t1);
    }

    for (int i = 1; i <= n; i++) {
        if (map[i].size() != 0) {
            sort(map[i].begin(), map[i].end());
        }
    }

    dfs(v);
    cout << '\n';

    queue<int> q;
    q.push(v);
    visited.assign(n+1, false);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if(visited[x]) {
            continue;
        }
        cout << x << " ";
        visited[x] = true;
        for(int i = 0; i < map[x].size(); i++) {
            q.push(map[x][i]);
        }
    }
    
    return 0;
}