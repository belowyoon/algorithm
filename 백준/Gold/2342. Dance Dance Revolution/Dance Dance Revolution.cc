#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1000000000

int dp[100001][5][5];
vector<int> ddr;
int n;

int calStrength(int cur, int x) {
    if (cur == x) {
        return 1;
    }
    if (cur == 0) {
        return 2;
    }
    if (abs(cur - x) == 1 || abs(cur - x) == 3) {
        return 3;
    }
    if (abs(cur - x) == 2) {
        return 4;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    int t = -1;
    while (t != 0){
        cin >> t;
        if (t != 0) ddr.push_back(t);
    }
    n = ddr.size();

    fill_n(&dp[0][0][0], 100001 * 5 * 5, INF);
    dp[0][0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for(int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if(dp[i-1][j][k] == INF) {
                    continue;
                }
                else {
                    dp[i][ddr[i-1]][k] = min(dp[i][ddr[i-1]][k], dp[i-1][j][k] + calStrength(j, ddr[i-1]));
                    dp[i][j][ddr[i-1]] = min(dp[i][j][ddr[i-1]], dp[i-1][j][k] + calStrength(k, ddr[i-1]));
                }
            }
        }
    }
    int res = INF;
    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5; k++) {
            res = min(dp[n][j][k], res);    
        }
    }
    
    cout << res;
    return 0;
}