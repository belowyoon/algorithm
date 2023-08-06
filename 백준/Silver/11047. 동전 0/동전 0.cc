#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);

    int n, k;
    int coin[10] = {0};
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    int result = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (k - coin[i] >= 0) {
            result += k / coin[i];
            k %= coin[i];
        }
    }
    cout << result;
    return 0;
}