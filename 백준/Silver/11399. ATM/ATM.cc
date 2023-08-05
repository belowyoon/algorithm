#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);

    int n;
    int arr[1000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i-1] + arr[i];
        result += arr[i];
    }
    cout << result;
    return 0;
}