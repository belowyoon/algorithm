#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> house(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }
    sort(house.begin(),house.end());

    int s = 1, e = house[n-1] - house[0], ans = 0;
    while(s <= e) {
        int r = 1;
        int mid = (s + e) / 2;
        int x = house[0];
        for (int i = 1; i < n; i++) {
            if (house[i] - x >= mid) {
                r++;
                x = house[i];
            }
        }
        if (r >= m) {
            ans = max(ans, mid);
            s = mid+1;
        } else {
            e = mid-1;
        }
    }
    cout << ans;

    return 0;
}
