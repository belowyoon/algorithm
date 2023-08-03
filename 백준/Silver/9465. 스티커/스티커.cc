#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        int sticker[2][100001] = {0};
        int dp[2][100001] = {0};
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> sticker[0][i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> sticker[1][i];
        }

        dp[0][1] = sticker[0][1];
        dp[1][1] = sticker[1][1];

        for (int i = 2; i <= n; i++) {
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) +  sticker[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) +  sticker[1][i];
        }

        cout << max(dp[0][n], dp[1][n]) << '\n';
    }

    return 0;
}
