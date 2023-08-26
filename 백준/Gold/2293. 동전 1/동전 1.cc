#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n, k;
    cin >> n >> k;

    vector<int> coin;
    vector<int> dp;
    coin.assign(n, 0);
    dp.assign(k+1, 0);

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= coin[i]) {
                dp[j] += dp[j - coin[i]];
            }
        }
    }
    cout << dp[k];

    return 0;
}