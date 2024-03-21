#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    int t, k;
    cin >> t >> k;
    vector<vector<int>> dp(k+1, vector<int>(t+1, 0));
    vector<pair<int, int>> coins;
    int p, n;
    for (int i = 0; i < k; i++) {
        cin >> p >> n;
        coins.push_back({p, n});
    }

    dp[0][0] = 1;
    for (int i = 0; i < k; i++) {
        p = coins[i].first, n = coins[i].second;
        for (int j = 0; j <= t; j++) {
            dp[i+1][j] = dp[i][j];
        }
        while (n > 0) {
            for (int j = 0; j <= t; j++) {
                if (dp[i][j] != 0 && j+p <= t) {
                    dp[i+1][j+p] += dp[i][j];
                }
            }
            n--;
            p += coins[i].first;
        }
    }
    cout << dp[k][t];
    return 0;
}