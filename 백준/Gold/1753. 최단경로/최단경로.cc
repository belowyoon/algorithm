#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int v, e, k;
    cin >> v >> e >> k;
    vector<vector<pair<int, int>>> map(v+1, vector<pair<int, int>>());
    int u, v2, w;
    for (int i = 0; i < e; i++) {
        cin >> u >> v2 >> w;
        map[u].push_back({v2, w});
    }

    priority_queue<pair<int, int>> pq;
    vector<int> dists(v+1, 10000000);
    pq.push({0, k});
    dists[k] = 0;

    while (!pq.empty()) {
        int x = pq.top().second, dist = -pq.top().first;
        pq.pop();
        if (dists[x] < dist) {
            continue;
        }
        for (int i = 0; i < map[x].size(); i++) {
            int nx = map[x][i].first, ndist = dists[x] + map[x][i].second;
            if (dists[nx] > ndist) {
                dists[nx] = ndist;
                pq.push({-ndist, nx});
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        if (dists[i] == 10000000) cout << "INF\n";
        else cout << dists[i] << '\n';    
    }
    
    return 0;
}
