#include <iostream>
#include <algorithm>
using namespace std;


int solution(int alp, int cop, vector<vector<int>> problems) {
    int n = problems.size(), maxAlp = alp, maxCop = cop;
    for (int i = 0; i < n; i++) {
        maxAlp = max(maxAlp, problems[i][0]);
        maxCop = max(maxCop, problems[i][1]);
    }
    vector<vector<int>> dp;
    dp.assign(maxAlp + 1, vector<int>(maxCop + 1, 1000000000));
    dp[alp][cop] = 0;
    if (alp >= maxAlp) alp = maxAlp;
    if (cop >= maxCop) cop = maxCop;
    for (int i = alp; i <= maxAlp; i++) {
        for (int j = cop; j <= maxCop; j++) {
            if (i+1 <= maxAlp) dp[i+1][j] = min(dp[i][j] + 1, dp[i+1][j]);
            if (j+1 <= maxCop) dp[i][j+1] = min(dp[i][j] + 1, dp[i][j+1]);
            for (int k = 0; k < n; k++) {
                int nxtI = i + problems[k][2];
                int nxtJ = j + problems[k][3];
                if (nxtI > maxAlp) nxtI = maxAlp;
                if (nxtJ > maxCop) nxtJ = maxCop;
                if (i >= problems[k][0] && j >= problems[k][1]) {
                    dp[nxtI][nxtJ] = min(dp[i][j] + problems[k][4], dp[nxtI][nxtJ]);
                }
            }
        }
    }
    return dp[maxAlp][maxCop];
}