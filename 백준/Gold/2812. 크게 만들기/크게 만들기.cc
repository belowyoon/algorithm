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
    
    int n, k;
    cin >> n >> k;

    vector<int> arr(n, 0);
    vector<int> res;

    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        arr[i] = c - '0';
    }

    stack<int> s;
    int t = k;
    for (int i = 0; i < n; i++) {
        while(!s.empty() && t > 0 && arr[i] > s.top()) {
            s.pop();
            t--;
        }
        s.push(arr[i]);
    }
    while(t > 0){
        t--;
        s.pop();
    }
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    for (int i = res.size()-1; i >= 0; i--) {
        cout << res[i];
    }
    return 0;
}