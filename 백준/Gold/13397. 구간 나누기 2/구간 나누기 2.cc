#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, res;
vector<int> arr;

bool divisible(int mid) {
    int cnt = 1;
    int minN = arr[0], maxN = arr[0];
    for (int i = 1; i < n; i++) {
        minN = min(arr[i], minN);
        maxN = max(arr[i], maxN);
        if (maxN - minN > mid) {
            minN = arr[i];
            maxN = arr[i];
            cnt++;
        }
        if (cnt > m) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n >> m;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int l = 0, r = *max_element(arr.begin(), arr.end());
    res = r;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (divisible(mid)) {
            if (res > mid) res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res;
    return 0;
}