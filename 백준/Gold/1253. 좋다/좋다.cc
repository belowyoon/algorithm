#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    int n;
    cin >> n;
    vector<int> arr(n,0);
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if (map.find(arr[i]) == map.end()) {
            map.insert({arr[i], 1});
        }
        else map[arr[i]]++;
    }
    int good = 0;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        map[arr[i]]--;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            map[arr[j]]--;
            if (map.find(arr[i] - arr[j]) != map.end() && map[arr[i] - arr[j]] > 0) {
                flag = true;
                map[arr[j]]++;
                break;
            }
            map[arr[j]]++;
        }
        if (flag) good++;
        map[arr[i]]++;
    }
    cout << good;
    return 0;
}