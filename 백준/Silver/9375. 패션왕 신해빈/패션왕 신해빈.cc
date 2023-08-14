#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int t, n;
    cin >> t;

    while (t > 0) {
        t--;
        cin >> n;
        unordered_map<string, int> map;
        unordered_map<string, int>::iterator iter;

        string type;
        for (int i = 0; i < n; i++) {
            cin >> type >> type;
            if (map.find(type) == map.end()) {
                map[type] = 1;
            } else {
                map[type]++;
            }
        }
        int result = 1;
        for (iter = map.begin(); iter != map.end(); iter++) {
            result *= iter->second + 1;
        }
        cout << result - 1 << '\n';
    }

    return 0;
}