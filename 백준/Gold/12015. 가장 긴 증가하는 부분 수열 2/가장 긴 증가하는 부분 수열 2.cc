#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

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

    vector<int> sorted;
    sorted.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        if (sorted[sorted.size()-1] < arr[i]) {
            sorted.push_back(arr[i]);
        } else {
            int s = 0, e = sorted.size()-1, mid;
            while (s < e) {
                mid = (s + e) / 2;
                if (arr[i] > sorted[mid]) {
                    s = mid + 1;
                } else {
                    e = mid;
                }
            }
            sorted[s] = arr[i];
        }
    }
    cout << sorted.size();
    return 0;
}
