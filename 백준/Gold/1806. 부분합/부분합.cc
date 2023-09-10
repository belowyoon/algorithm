#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n, s;
    vector<int> num;
    cin >> n >> s;
    num.assign(n,0);

    int total = 0;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        total += num[i];
        if (num[i] >= s) {
            cout << 1;
            return 0;
        }
    }
    if (total < s) {
        cout << 0;
        return 0;
    } 

    int l = 0, r = 0;
    int sum = 0;
    int result = n+1;
    while (l < n)
    {
        while (sum < s && r < n) {
            sum += num[r];
            r++;
        }
        if (sum >= s) {
            result = min(r - l, result);
        }
        sum -= num[l];
        l++;
    }
    cout << result;
    return 0; 
}