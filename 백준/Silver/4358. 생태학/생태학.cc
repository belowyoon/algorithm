#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    string str;
    int cnt = 0;
    unordered_map<string, int> map;
    vector<string> trees;

    while (getline(cin,str)) {
        cnt++;
        if (map.find(str) == map.end()) {
            map[str] = 1;
            trees.push_back(str);
        } else {
            map[str]++;
        }
    }
    sort(trees.begin(),trees.end());
    float num;
    for (int i = 0; i < trees.size(); i++) {
        num = round((float(map[trees[i]]) / cnt * 100) * 10000) / 10000;
        cout << fixed;
        cout.precision(4);
        cout << trees[i] << " " << num << '\n'; 
    }
    return 0;
}