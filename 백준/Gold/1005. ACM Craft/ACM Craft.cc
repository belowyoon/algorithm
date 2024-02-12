#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > map;
vector<int> depths;
vector<int> times;
vector<int> result;
int n, r;

int topology_sort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (depths[i] == 0) {
            q.push(i);
        }
    }
    while(depths[r] > 0) {
        int x = q.front();
        q.pop();
        for (int j = 0; j < map[x].size(); j++) {
            result[map[x][j]] = max(result[map[x][j]], result[x] + times[x]);
            if (--depths[map[x][j]] == 0) {
                q.push(map[x][j]);
            }
        }
    }
    return result[r] + times[r];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t > 0) {
        int t1, t2, k;
        cin >> n >> k;

        map.assign(n+1, vector<int>());
        depths.assign(n+1, 0);
        times.assign(n+1, 0);
        result.assign(n+1, 0);

        for(int i = 1; i <= n; i++) {
            cin >> times[i];
        }
        for (int i = 0; i < k; i++){
            cin >> t1 >> t2;
            map[t1].push_back(t2);
            depths[t2]++;
        }
        cin >> r;
        cout << topology_sort() << '\n';
        t--;
    }
    return 0;
}