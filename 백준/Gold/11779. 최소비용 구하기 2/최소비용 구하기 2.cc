#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1000000001

using namespace std;

int n, m, s, e;
vector<pair<int, int>> bus[1001];

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    vector<int> costs(n+1, INF);
    vector<int> prev(n+1, -1);
    pq.push({0, s});
    costs[s] = 0;
    while (!pq.empty()) {
        int x = pq.top().second, cost = -pq.top().first;
        pq.pop();
        if (costs[x] < cost) {
            continue;
        }
        for (int i = 0; i < bus[x].size(); i++) {
            int nx = bus[x][i].first, ncost = bus[x][i].second + cost;
            if (costs[nx] > ncost) {
                costs[nx] = ncost;
                prev[nx] = x;
                pq.push({-ncost, nx});
            }
        }
    }
    cout << costs[e] << '\n';
    vector<int> routes;
    int idx = e;
    while (idx != s) {
        routes.push_back(idx);
        idx = prev[idx];
    }
    routes.push_back(s);
    cout << routes.size() << '\n';
    for (int i = routes.size()-1; i >= 0; i--) {
        cout << routes[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int x;
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> x;
        bus[s].push_back({e,x});
    }
    cin >> s >> e;
    dijkstra();

    return 0;
}
