#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    string one;
    string two;
    getline(cin,one);
    getline(cin,two);
    vector<vector<int>> dp;
    dp.assign(two.size(), vector<int>(one.size(),0));

    int flag = false;
    for(int i = 0; i < one.size(); i++) {
        if (one[i] == two[0]  || flag) {
            dp[0][i] = 1;
            flag = true;
        }
    }

    flag = false;
    for(int i = 0; i < two.size(); i++) {
        if (one[0] == two[i] || flag) {
            dp[i][0] = 1;
            flag = true;
        }
    }

    for (int i = 1; i < two.size(); i++) {
        for (int j = 1;  j < one.size(); j++) {
            if (two[i] == one[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // for (int i = 0; i < two.size(); i++) {
    //     for (int j = 0;  j < one.size(); j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << dp[two.size()-1][one.size()-1];


    return 0;
}