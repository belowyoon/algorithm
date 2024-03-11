#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    s1 = " " + s1;
    s2 = " " + s2;

    vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), 0));
    
    for (int i = 1; i < s1.size(); i++) {
        for (int j = 1; j < s2.size(); j++) {
            if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int x = s1.size()-1, y = s2.size()-1;
    int res = dp[s1.size()-1][s2.size()-1];

    vector<char> ans;
    while (dp[x][y]) {
        if (dp[x][y] == dp[x-1][y]) {
            x--;
        } else if (dp[x][y] == dp[x][y-1]) {
            y--;
        } else {
            ans.push_back(s1[x]);
            x--;
            y--;
        }
    }
    cout << res << '\n';
    if (res) {
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i];
        }
    }
    return 0;
}