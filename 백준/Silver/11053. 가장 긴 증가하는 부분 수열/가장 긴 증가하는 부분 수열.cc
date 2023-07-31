#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    int num[1000] = {0};
    int dp[1000];
    int result = 1;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (num[i] > num[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result,dp[i]);
    }
    
    cout << result;
    return 0;
}