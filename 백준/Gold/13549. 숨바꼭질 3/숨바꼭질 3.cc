#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    priority_queue<pair<int, int>> pq;
    vector<int> dp(100001, 100001);
    pq.push({0, n});
    int cnt = 0;
    while (!pq.empty()) {
        int x = pq.top().second;
        dp[x] = -pq.top().first;
        pq.pop();
        if (x == k) break;
        if (x-1 >= 0 && dp[x-1] > dp[x]+1) {
            pq.push({-(dp[x]+1), x-1});
        }
        if (x+1 <= 100000 && dp[x+1] > dp[x]+1) {
            pq.push({-(dp[x]+1), x+1});
        }
        if (x*2 <= 100000 && dp[x*2] > dp[x]) {
            pq.push({-(dp[x]), x*2});
        }
    }
    
    cout << dp[k];
    return 0;
}
