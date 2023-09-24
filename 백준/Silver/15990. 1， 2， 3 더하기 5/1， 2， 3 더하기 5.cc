#include <iostream>
#include <algorithm>
#define DIVISOR 1000000009
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int t, n;
    cin >> t;
    int dp[100001][3] = {0,};
    dp[1][0] = 1;
    dp[2][1] = 1;
    dp[3][0] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    for (int i = 4; i < 100001; i++) {
        dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % DIVISOR;
        dp[i][1] = (dp[i-2][0] + dp[i-2][2]) % DIVISOR;
        dp[i][2] = (dp[i-3][0] + dp[i-3][1]) % DIVISOR;
    }
    for (int i = 0; i < t; i++){
        cin >> n;
        int result = 0;
        for (int j = 0; j < 3; j++) {
            result += dp[n][j];
            result %= DIVISOR;
        }
        cout << result << "\n";
    }
    return 0;
}