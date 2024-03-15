#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 100000000
using namespace std;

vector<vector<pair<int, int>>> edges;
int n, e, a, b, c, u, v;
vector<int> dist;

void calc(int start) {
    dist.assign(n+1, INF);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
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
    return;
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

    calc(1);
    int toU = dist[u], toV = dist[v];
    calc(u);
    int UtoV = dist[v], UtoN = dist[n];
    calc(v);
    int VtoN = dist[n];
    
    int result = min(toU + VtoN, toV + UtoN) + UtoV;
    if (result >= INF) cout << -1;
    else cout << result;
    return 0;
}
