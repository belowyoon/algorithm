#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n+1, vector<int>());
    vector<int> degree(n+1, 0);

    int size;
    for (int i = 0; i < m; i++) {
        cin >> size;
        vector<int> tmp(size, 0);
        for (int j = 0; j < size; j++) {
            cin >> tmp[j];
        }
        for (int j = 0; j < size; j++) {
            for (int k = j+1; k < size; k++) {
                map[tmp[j]].push_back(tmp[k]);
                degree[tmp[k]]++;
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for (int i = 0; i < map[x].size(); i++) {
            int nx = map[x][i];
            degree[nx]--;
            if (degree[nx] == 0) q.push(nx);
        }
    }
    
    if (ans.size() != n) {
        cout << "0";
    } else {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << '\n';
        }
    }

    return 0;
}
