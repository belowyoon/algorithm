#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    int n, k, w, v;
    cin >> n >> k;
    pair<int, int> num[101];
    vector <vector<int> > dp;
    dp.assign(n+1, vector<int>(k+1,0));

    for (int i = 1; i <= n; i++) {
        cin >> w >> v;
        num[i] = make_pair(w,v);
    }

    for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			 if (j - num[i].first >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - num[i].first] +  num[i].second);
			 else dp[i][j] = dp[i - 1][j];
		}
	}


    cout << dp[n][k];

    return 0;
}