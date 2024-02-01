#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> map;
vector<int> depths;
vector<int> result;
int n, m;

void topology_sort() {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (depths[i] == 0) {
            pq.push(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        int x = pq.top();
        pq.pop();
        result[i] = x;
        for (int j = 0; j < map[x].size(); j++) {
            if (--depths[map[x][j]] == 0) {
                pq.push(map[x][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int t1, t2;
    cin >> n >> m;
    map.assign(n+1, vector<int>());
    depths.assign(n+1, 0);
    result.assign(n+1, 0);

    for (int i = 0; i < m; i++){
        cin >> t1 >> t2;
        map[t1].push_back(t2);
        depths[t2]++;
    }
    topology_sort();

    return 0;
}