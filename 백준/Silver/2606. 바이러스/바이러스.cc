#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>visited;
vector<vector<int>> map;
int cnt = 0;

void dfs(int k) {
    if (visited[k] == 1) {
        return;
    }
    visited[k] = 1;
    cnt++;
    for (int i = 0; i < map[k].size(); i++){
        dfs(map[k][i]);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    int n , m;
    cin >> n >> m;
    map.assign(n,vector<int>(0));
    visited.assign(n,0);

    for (int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        map[t1-1].push_back(t2-1);
        map[t2-1].push_back(t1-1);
    }

    dfs(0);
    cout << cnt - 1;
    

    return 0;
}
