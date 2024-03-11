#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    int n;
    cin >> n;
    vector<int> num(n, 0);
    vector<int> res(n, 0);
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
        map.insert({num[i], i});
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= sqrt(num[i]); j++) {
            if (num[i] % j == 0) {
                if (map.find(j) != map.end()) {
                    res[map[j]]++;
                    res[i]--;
                }
                if (num[i] / j != j && map.find(num[i] / j) != map.end()) {
                    res[map[num[i] / j]]++;
                    res[i]--;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    return 0;
}