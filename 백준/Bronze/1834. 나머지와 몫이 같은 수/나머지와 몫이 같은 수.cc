#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    long long res = 0;
    for(int i = 1; i < n; i++) {
        res += (long long)(n + 1) * i;
    }
    cout << res;
    return 0;
}