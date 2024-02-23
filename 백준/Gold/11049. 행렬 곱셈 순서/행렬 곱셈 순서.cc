#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int dp[501][501];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    int n;
    cin >> n;
    vector<vector<int> > matrix;
    matrix.assign(n+1, vector<int>(2,0));

    for(int i = 1; i <= n; i++){
        cin >> matrix[i][0] >> matrix[i][1];
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 1; i + j <= n; j++){
            dp[j][i + j] = 1000000001;
            for (int k = j; k <= i + j; k++){
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i+j][1]);
			}
        }
    }
    cout << dp[1][n];
    return 0;
}