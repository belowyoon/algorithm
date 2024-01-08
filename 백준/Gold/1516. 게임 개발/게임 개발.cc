#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> seconds;
vector<bool> visited;
vector<vector<int>> prevs;

void check(int b) {
    if (visited[b])
        return;
    int s = 0;
    for (int i = 0; i < prevs[b].size(); i++) {
        if (!visited[prevs[b][i]]) {
            check(prevs[b][i]);
        }
        s = max(s, seconds[prevs[b][i]]);
    }
    seconds[b] += s;
    visited[b] = true;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    int n;
    cin >> n;
    seconds.assign(n, 0);
    visited.assign(n, false);
    prevs.assign(n, vector<int>());
    
    int t;
    for (int i = 0; i < n; i++) {
        cin >> seconds[i];
        cin >> t;
        while(t != -1) {
            prevs[i].push_back(t - 1);
            cin >> t;
        }
    }
    for (int i = 0; i < n; i++) {
        check(i);
    }
    for (int i = 0; i < n; i++) {
        cout << seconds[i] << '\n';
    }
    return 0;
}