#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, p;
    cin >> n;
    vector<int> t(n+1, 0);
    vector<vector<int>> pre(n+1, vector<int>());
    vector<int> dp(n+1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> p;
            pre[i].push_back(p);
        }
    }

    for (int i = 1; i <= n; i++) {
        int maxWait = 0;
        for (int j = 0; j < pre[i].size(); j++) {
            maxWait = max(dp[pre[i][j]], maxWait);
        }
        dp[i] = maxWait + t[i];
    }
    cout << *max_element(dp.begin(), dp.end());

    return 0;
}
