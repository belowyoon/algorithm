#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    int t, n, a1, a2;
    cin >> t;
    while (t > 0) {
        cin >> n;
        vector<pair <int, int>> applicant;
        for (int i = 0; i < n; i++) {
            cin >> a1 >> a2;
            applicant.push_back({a1, a2});
        }
        sort(applicant.begin(), applicant.end());
        int rank = n + 1, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (applicant[i].second < rank) {
                cnt++;
                rank = applicant[i].second;
            }
        }
        cout << cnt << '\n';
        t--;
    }
}