#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map;
    vector<int> d;
    vector<int> res;
    map.assign(n + 1, vector<int>());
    d.assign(n+1, 0);
    res.assign(n+1, 0);
    int t1, t2;
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2;
        map[t1].push_back(t2);
        d[t2]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) q.push(i);
    }
    for (int i = 1; i <= n; i++) {
        if (q.empty()) {
            break;
        }
        int x = q.front();
        q.pop();
        res[i] = x;
        for(int j = 0; j < map[x].size(); j++) {
            int nx = map[x][j];
            if (--d[nx] == 0) {
                q.push(nx);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    return 0;
}