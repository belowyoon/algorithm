#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    int time[16];
    int profit[16];
    int dp[16][16] = {0};

    for (int i = 1; i <= n; i++) {
        cin >> time[i];
        cin >> profit[i];
    }

    for (int i = 1; i <= n; i++) {
        if (i + time[i] )
        for (int j = 1; j <= n; j++) {
            if (j >= i + time[i] - 1) {
                dp[i][j] = max(dp[i-1][i-1] + profit[i], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }    
        }
    }

    cout << dp[n][n];
    return 0;
}