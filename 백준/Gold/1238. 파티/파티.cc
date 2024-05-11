#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, x;
vector<vector<pair<int, int>>> map;
vector<int> res;

void dij(int s) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    vector<int> times(n+1, 10000000);
    while (!pq.empty()){
        int h = pq.top().second, t = -pq.top().first;
        pq.pop();
        if (times[h] < t) continue;
        for(int i = 0; i < map[h].size(); i++) {
            int nh = map[h][i].first, nt = map[h][i].second + t;
            if (times[nh] > nt) {
                times[nh] = nt;
                pq.push({-nt, nh});
            }
        }
    }
    if (x != s) {
        res[s] += times[x];
    } else {
        for (int i = 1; i <= n; i++) {
            if (x != i) res[i] += times[i];
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x;
    map.assign(n+1, vector<pair<int,int>>());
    res.assign(n+1, 0);

    int a, b, t;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        map[a].push_back({b, t});
    }

    for (int i = 1; i <= n; i++) {
        dij(i);
    }

    cout << *max_element(res.begin(), res.end());
    return 0;
}