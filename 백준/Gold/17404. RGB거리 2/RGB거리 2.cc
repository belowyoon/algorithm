#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> rgb;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    rgb.assign(n+1, vector<int>(3, 0));
    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> rgb[i][j];
        }
    }

    int ans = 10000000;
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 3; i++) {
            if (i == k) dp[1][i] = rgb[1][i];
            else dp[1][i] = 10000000;
        }
        for (int i = 2; i <= n; i++) {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + rgb[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + rgb[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + rgb[i][2];
        }
        for (int i = 0; i < 3; i++) {
            if (i != k) ans = min(ans, dp[n][i]);
        }
    }
    cout << ans;

    return 0;
}
