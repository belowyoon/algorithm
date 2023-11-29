#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    int n;
    cin >> n;
    vector<int> rope;
    rope.assign(n,0);
    int result = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> rope[i];
    }

    sort(rope.begin(), rope.end());

    for (int i = 0; i < n; i++) {
        result = max(result, rope[i] * (n-i));
    }
    cout << result;
    
    return 0;
}