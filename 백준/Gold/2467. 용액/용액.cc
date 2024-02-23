#include <iostream>
#include <algorithm>
#include <vector>
#include  <stdlib.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    int n;
    cin >> n;
    vector<int> liq;
    liq.assign(n,0);

    for(int i = 0; i < n; i++) {
        cin >> liq[i];
    }
    int s = 0, e = n-1;
    int minResult = 2000000001;
    int x, y;
    while (s != e) {
        int sum = liq[s] + liq[e];
        if (minResult >= abs(sum)) {
            minResult = abs(sum);
            x = s; y = e;
        } 
        if (sum < 0) {
            s++;
        } else if (sum > 0) {
            e--;
        } else {
            break;
        }
    }
    cout << liq[x] << " " << liq[y];
    
    return 0;
}