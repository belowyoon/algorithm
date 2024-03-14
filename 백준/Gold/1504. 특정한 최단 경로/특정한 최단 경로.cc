#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;

vector<vector<pair<int, int>>> edges;
int n, e, a, b, c, u, v;

pair<int, int> calc(int start, int e1, int e2) {
    vector<int> dist(n+1, INF);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int node = pq.top().second;
;       pq.pop();
        if (cost > dist[node])
            continue;
        for (int i = 0; i < edges[node].size(); i++) {
            int nc = cost + edges[node][i].second;
            int nn = edges[node][i].first;
            if (nc < dist[nn]) {
                pq.push({nc, nn});
                dist[nn] = nc;
            }
        }
    }
    return {dist[e1], dist[e2]};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    cin >> n >> e;
    edges.assign(n+1, vector<pair<int,int>>());
    for(int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    cin >> u >> v;
    pair<int, int> r1 = calc(1, u, v);
    pair<int, int> r2 = calc(u, v, n);
    pair<int, int> r3 = calc(v, n, 0);
    long long result = min((long long)r1.first + r3.first, (long long)r1.second + r2.second) + (long long)r2.first;
    if (result >= INF) cout << -1;
    else cout << result;
    return 0;
}