#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    vector<int> ans(3,0);
    long long num = 3000000001;
    
    for (int i = 0; i < n; i++) {
        int l = i+1, r = n-1;
        while (l < r) {
            long long tmp = (long long)arr[i] + arr[l] + arr[r];
            long long abstmp = (tmp < 0) ? tmp * -1: tmp;
            if (abstmp < num) {
                num = abstmp;
                ans[0] = arr[i];
                ans[1] = arr[l];
                ans[2] = arr[r];
            }
            if (tmp > 0) {
                r--;
            } else if (tmp < 0) {
                l++;
            } else {
                break;
            }
    
        }
        if (num == 0) break;
    }

    for (int i = 0; i < 3; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
