#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321;

using namespace std;

int n, allVisited;
vector<vector<int>> map;
vector<vector<int>> dp;

int dfs(int cur, int visitedBit) {
    if (visitedBit == allVisited) {
        if (map[cur][0] != 0) return map[cur][0];
        else return INF;
    } 

    if (dp[cur][visitedBit] != -1) return dp[cur][visitedBit];

    dp[cur][visitedBit] = INF;
    for (int i = 0; i < n; i++) {
        if (map[cur][i] == 0 || (visitedBit & (1<<i)) == (1<<i)) continue;
        dp[cur][visitedBit] = min(dp[cur][visitedBit], map[cur][i] + dfs(i, visitedBit|1<<i));
    }
    return dp[cur][visitedBit];
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    map.assign(n, vector<int>(n,0));
    dp.assign(n, vector<int>(1<<n, -1));
    allVisited = (1<<n) - 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    cout << dfs(0, 1);
    return 0;
}
