#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    int n, d, w, last = 0;
    cin >> n;
    vector<pair<int, int>> score;
    for (int i = 0; i < n; i++) {
        cin >> d >> w;
        score.push_back({w, d});
        last = max(last, d);
    }
    sort(score.begin(), score.end(), greater<pair<int, int>>());
    vector<int> ans(last + 1, 0);
    for (int i = 0; i < n; i++) {
        d = score[i].second; w = score[i].first;
        while(d) {
            if (ans[d] == 0) {
                ans[d] = w;
                break;
            }
            d--;
        }
    }
    int res = 0;
    for (int i = 1; i <= last; i++) {
        res += ans[i];
    }
    cout << res;
    return 0;
}