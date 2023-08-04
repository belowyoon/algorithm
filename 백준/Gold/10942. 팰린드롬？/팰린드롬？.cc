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

    int n;
    cin >> n;
    vector< vector<int> > dp;
    vector<int> num;
    num.assign(n, 0);
    dp.assign(n, vector<int>(n,0));

    
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        for (int j = 0; j <= i; j++) {
            dp[i][j] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        // i는 j - j+i까지 보는 역할
        for (int j = 0; j < n - i; j++) {
            //cout << j << " " << j+i << '\n';
            if (num[j] == num[j+i] && dp[j+1][j+i-1] == 1) {
                dp[j][j+i] = 1;
            } 
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0;  j < n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    int t, x, y;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> x >> y;
        cout << dp[x-1][y-1] << '\n';
    }

    return 0;
}