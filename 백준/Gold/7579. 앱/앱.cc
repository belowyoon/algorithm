#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > app(n+1, {0,0});
    vector<vector<int> > dp(n+1, vector<int>(10001, 0));
    int sum = 0;

    for(int i = 1; i <= n; i++) {
        cin >> app[i].second;
    }
    for(int i = 1; i <= n; i++) {
        cin >> app[i].first;
        sum += app[i].first;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j - app[i].first >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-app[i].first] + app[i].second);
            }
            dp[i][j] = max(dp[i-1][j], dp[i][j]);
        }
    }
    for (int j = 0; j <= sum; j++) {
        if(dp[n][j] >= m) {
            cout << j;
            break;
        }
    }
    return 0;
}
