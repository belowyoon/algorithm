#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    vector<int> res(n, -1);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<int> s;
    for (int i = n-1; i >= 0; i--) {
        while(!s.empty()) {
            if (s.top() > arr[i]) break;
            s.pop();
        }
        if (s.empty()) res[i] = -1;
        else  res[i] = s.top();
        s.push(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    return 0;
}