#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    vector<int> dp;
    int n, m, a, b;

    cin >> n >> m;
    dp.assign(n+1 , 1);

    vector<pair <int, int>> prerequisite;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        prerequisite.push_back({a,b});
    }

    sort(prerequisite.begin(), prerequisite.end());

    for (int i = 0; i < prerequisite.size(); i++) {
        a = prerequisite[i].first; b = prerequisite[i].second;
        dp[b] = max(dp[a] + 1, dp[b]);
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }

    return 0;
}