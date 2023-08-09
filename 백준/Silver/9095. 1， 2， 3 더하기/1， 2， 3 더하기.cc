#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);

    int t;
    int dp[12];

    cin >> t;
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i < 12; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}