#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n, m, t;
    vector<int> num;
    unordered_set<int> set;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> t;
        int size = num.size();
        for (int j = 0; j < size; j++) {
            if (set.find(t + num[j]) == set.end()) {
                num.push_back(t + num[j]);
                set.insert(t + num[j]);
            }
        }
        if (set.find(t) == set.end()) {
            num.push_back(t);
            set.insert(t);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        bool flag = false;
        if(set.find(t) != set.end()) {
            cout << "Y ";
            continue;
        } 
        for (int j = 0; j < num.size(); j++) {
            if (set.find(t + num[j]) != set.end()) {
                flag = true;
                break;
            }
        }
        if(flag) {
            cout << "Y ";
        } else {
            cout << "N ";
        }
    }

    return 0;
}