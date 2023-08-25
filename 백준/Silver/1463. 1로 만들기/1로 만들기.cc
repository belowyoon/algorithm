#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main () 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    vector<int> dp;
    dp.assign(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + 1;
        if (i % 3 == 0) {
            dp[i] = min(dp[i/3] + 1, dp[i]);
        } 
        if (i % 2 == 0) {
            dp[i] = min (dp[i/2] + 1, dp[i]);
        } 
    }

    cout << dp[n];
    return 0;
}