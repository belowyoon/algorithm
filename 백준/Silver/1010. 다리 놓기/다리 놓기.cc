#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, m;
        int result = 1;
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            result *= m - i;
            result /= 1 + i;
        }
        cout << result << '\n';
    }
    return 0;
}