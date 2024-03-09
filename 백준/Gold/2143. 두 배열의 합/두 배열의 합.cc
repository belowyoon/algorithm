#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int t, n, m;
    
    cin >> t >> n;
    vector<int> a(n,0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m,0);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for(int i = 0; i < n; i++) {
        int s = a[i];
        for (int j = i + 1; j < n; j++) {
            s += a[j];
            a.push_back(s);
        }
    }
    for(int i = 0; i < m; i++) {
        int s = b[i];
        for (int j = i + 1; j < m; j++) {
            s += b[j];
            b.push_back(s);
        }
    }

    long long res = 0;
    sort(b.begin(), b.end());
    for(int i = 0; i < a.size(); i++){
        int idx = lower_bound(b.begin(),b.end(),t - a[i]) - b.begin();
        int endIdx = upper_bound(b.begin(),b.end(),t - a[i]) - b.begin();
        res += endIdx - idx;
    }
    cout << res;
    return 0;
}