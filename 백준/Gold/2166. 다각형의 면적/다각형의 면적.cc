#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<vector<int>> xy(n, vector<int>(2,0));
    for (int i = 0; i < n; i++) {
        cin >> xy[i][0] >> xy[i][1];
    }

    long long c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        c1 += xy[i][0] * (long long)xy[j][1];
        c2 += xy[j][0] * (long long)xy[i][1];
    }
    cout << fixed;
    cout.precision(1);
    double result = abs((double)c1 - (double)c2) / 2;
    cout << result;
    return 0;
}