#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    vector<int> road;
    vector<int> costs;
    vector<int> dp;
    cin >> n;
    road.assign(n, 0);
    costs.assign(n, 0);
    dp.assign(n, 0);
    for (int i = 0; i < n - 1; i++) {
        cin >> road[i];
    } 
     for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }
    int minCost = 1000000001;
    for (int i = 1; i < n; i++) {
        minCost = min(costs[i-1], minCost);
        dp[i] = dp[i-1] + (minCost * road[i-1]);
    }
    cout << dp[n-1];
    return 0;
}
