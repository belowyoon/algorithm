#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n, t1, t2, t3, t4;
    cin >> n;
    vector<pair<int, int>> f;

    for (int i = 0; i < n; i++){
        cin >> t1 >> t2 >> t3 >> t4;
        if (t1 <= 2) {
            t1 = 3; t2 = 1;
        }
        if (t3 >= 12) {
            t3 = 12; t4 = 1;
        }
        f.push_back({t1 * 100 + t2, t3 * 100 + t4});
    }
    sort(f.begin(), f.end());
    int cnt = 0, current = 301, temp = 301;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (f[i].first > current) {
            current = temp;
            cnt++;
        }
        if (f[i].first <= current) {
            temp = max(f[i].second, temp);
        } 
    }
    if (current != temp) {
        current = temp;
        cnt++;
    }
    if (current != 1201) cnt = 0;
    cout << cnt;
    return 0;
}
