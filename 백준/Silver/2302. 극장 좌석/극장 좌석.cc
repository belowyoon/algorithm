#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n, m;
    vector<int> dp;
    vector<int> vips;

    cin >> n >> m;
    dp.assign(n+1, 0);
    vips.assign(m, 0);

    for (int i = 0; i < m; i++){
        cin >> vips[i];
    }
    sort(vips.begin(), vips.end());

    int cnt = 2, index = 0, result = 1;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if(index < m && vips[index] == i){
            result *= dp[i-1];
            index++;
            cnt = 1;
        }
        if (cnt <= 2) {
            dp[i] = 1;
        } else {
            dp[i] = dp[i-1] + dp[i-2];
        }
        cnt++;
    }
    if ((m > 0 && vips[m-1] != n) || m == 0) {
        result *= dp[n];
    }
    cout << result;
    return 0;
}
