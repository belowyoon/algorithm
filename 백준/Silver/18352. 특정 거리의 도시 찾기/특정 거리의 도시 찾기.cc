#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n, m, k, x;
    cin >> n >> m >> k >> x;
    
    vector<vector<int>> map;
    vector<bool> visited;
    queue<int> q;
    map.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        map[t1].push_back(t2);
    }
    q.push(x);
    visited[x] = true;
    int size;
    while(k > 0) {
        k--;
        size = q.size();
        if (q.empty()) {
            cout << -1;
            return 0;
        }
        for (int i = 0; i < size; i++) {
            int city = q.front();
            q.pop();
            for (int j = 0; j < map[city].size(); j++) {
                if (!visited[map[city][j]]) {
                    visited[map[city][j]] = true;
                    q.push(map[city][j]);
                }
            }
        }
    }
    if (q.empty()) {
        cout << -1;
        return 0;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    while (!q.empty())
    {
        pq.push(q.front());
        q.pop();
    }
    while (!pq.empty())
    {
        cout << pq.top() << '\n';
        pq.pop();
    }

    return 0;
}