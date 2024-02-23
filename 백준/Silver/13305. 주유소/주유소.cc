#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    vector<int> road;
    vector<int> costs;
    cin >> n;
    road.assign(n, 0);
    costs.assign(n, 0);
    
    long long total = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> road[i];
    } 
     for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }
    long long minCost = 1000000001;
    for (int i = 1; i < n; i++) {
        if (minCost > costs[i-1]) {
            minCost = costs[i-1];
        } 
        total += minCost * road[i-1];
    }
    cout << total;
    return 0;
}
