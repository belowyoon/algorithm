#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> diamonds(n, {0, 0});
    vector<int> bags(k, 0);
    priority_queue<pair<int, int>> pq;

    int m, v;
    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        diamonds[i] = {m, v};
    }
    for (int i = 0; i < k; i++) {
        cin >> bags[i];
    }

    sort(diamonds.begin(), diamonds.end());
    sort(bags.begin(), bags.end());

    int idx = 0;
    long long res = 0;

    for (int i = 0; i < n; i++) {
        if (idx == k) break;
        if (diamonds[i].first > bags[idx]) {
            if (pq.empty()) {
                idx++;
                i--;
                continue;
            }
            res += (long long)pq.top().first;
            pq.pop();
            idx++;
            i--;
        } else {
            pq.push({diamonds[i].second, diamonds[i].first});
        }
    }
    while (idx < k && !pq.empty()) {
        res += (long long)pq.top().first;
        pq.pop();
        idx++;
    }
    cout << res;

    return 0;
}
