#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int map[1001][1001];
    int cost[1001];
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
    int n, m, s, e, w;

    cin >> n >> m;
    fill(map[0], map[n], 100000001);
    fill(cost, cost + n, 100000001);
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> w;
        map[s-1][e-1] = min(map[s-1][e-1], w); 
    }
    cin >> s >> e;
    cost[s-1] = 0;
    pq.push({cost[s-1], s-1});
    while (!pq.empty()) {
        int city = pq.top().second, sum = pq.top().first;
        pq.pop();
        for (int i = 0; i < n; i++) {
            if (map[city][i] != 100000001) {
                if (sum + map[city][i] < cost[i]) {
                    pq.push({sum + map[city][i], i});
                    cost[i] = sum + map[city][i];
                }
            }
        }
    }
    cout << cost[e-1];
    return 0;
}