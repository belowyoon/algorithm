#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    while(b) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n, sum = 0;

    cin >> n;
    vector<int> arr(n,0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    vector<int> subs;
    for (int i = 1; i < n; i++) {
        subs.push_back(arr[i] - arr[i-1]);
    }

    int result = subs[0];
    for (int i = 1; i < n-1; i++) {
        result = gcd(subs[i], result);
    }

    cout << result;
    return 0;
}