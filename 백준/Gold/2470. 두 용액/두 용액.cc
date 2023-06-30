#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr;
    int result[2];

    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int minDiff = 2000000001;

    sort(arr.begin(), arr.end());

    int l = 0;
    int r = n-1;

    while (l < r)
    {
        if (abs(arr[l] + arr[r]) < minDiff) {
            minDiff = abs(arr[l] + arr[r]);
            result[0] = arr[l];
            result[1] = arr[r];
        }
        if (arr[l] + arr[r] > 0) {
            r--;
        } else {
            l++;
        }
    }
    cout << result[0] << ' ' << result[1];

    return 0;
}