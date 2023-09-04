#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    vector<vector<bool>> train;
    train.assign(n, vector<bool>(20, false));

    unordered_set<string> result;

    int t1, t2, t3;
    for(int i = 0; i < m; i++) {
        cin >> t1 >> t2;
        if (t1 == 1) {
            cin >> t3;
            train[t2-1][t3-1] = true;
        } else if (t1 == 2) {
            cin >> t3;
            train[t2-1][t3-1] = false;

        } else if (t1 == 3) {
            vector<bool> temp(20, false);
            for (int j = 1; j < 20; j++) {
                temp[j] = train[t2-1][j-1];
            }
            train[t2-1] = temp;
        } else if (t1 == 4) {
             vector<bool> temp(20, false);
            for (int j = 0; j < 19; j++) {
                temp[j] = train[t2-1][j+1];
            }
            train[t2-1] = temp;
        }
    }

    for (int i = 0; i < n; i++) {
        string temp;
        for (int j = 0; j < 20; j++) {
            temp.push_back(train[i][j] + '0');
        }
        result.insert(temp);
    }
  
    cout << result.size();
    return 0;
}