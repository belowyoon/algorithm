#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    int n, s;
    cin >> n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> s;
    
    int f = 0;
    while(s > 0 && f < n) {
        int idx = f;
        for (int i = f; i <= min(f + s, n - 1); i++) {
            if (arr[i] > arr[idx]) idx = i;
        }
        for (int i = idx; i > f; i--) { 
            swap(arr[i-1], arr[i]);
            s--;
            if (s == 0) break;
        }
        f++;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}