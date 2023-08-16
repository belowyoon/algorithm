#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> dish;
    unordered_map<int, int> map;
    dish.assign(n, 0);
    
    for (int i = 0; i < n; i++)
    {
        cin >> dish[i];
    }

    map.insert({c,0});
    for (int i = 0; i < k; i++)
    {
        if (map.find(dish[i]) == map.end()) {
            map.insert({dish[i], 0});
        } else {
            map[dish[i]]++;
        }
    }

    int result = 0;
    int index;
    for (int i = 1; i <= n; i++)
    {
        index = (i + k - 1) % n;
        if (map[dish[i-1]] == 0) {
            map.erase(dish[i - 1]);
            
        } else {
            map[dish[i-1]]--;
        }
        if (map.find(dish[index]) == map.end()) {
            map.insert({dish[index], 0});
        } else {
            map[dish[index]]++;
        }
        int size = map.size();
        result = max(size, result);

    }
    
    cout << result;

    return 0;
}