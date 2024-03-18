#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    int n, k;
    cin >> n >> k;
    vector<int> s(n, 0);
    vector<int> h(n, 0);
    vector<vector<int>> dp(n+1, vector<int>(101, -1));
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    dp[0][100] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 100; j++) {
            if (dp[i][j] == -1) continue;
            int nxtH = j - h[i];
            if (nxtH >= 0) {
                nxtH = min(100, nxtH+k);
                dp[i+1][nxtH] =  max(dp[i][j] + s[i], dp[i+1][nxtH]);
            };
            nxtH = min(100, j + k);
            dp[i+1][nxtH] = max(dp[i+1][nxtH], dp[i][j]);
        }
    }
    cout << *max_element(dp[n].begin(), dp[n].end());
    return 0;
}