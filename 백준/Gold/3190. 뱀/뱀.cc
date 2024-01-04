#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, k, l;
vector<vector<int>> map;
vector<pair<int, char>> dir;
int dx[4] = {0, 1, 0 , -1};
int dy[4] = {1, 0, -1, 0};
int hx = 0, hy = 0, hIdx = 0, lIdx = 0;
queue<pair<int, int>> visited;

int move(int second){
    int tx, ty;
    hx += dx[hIdx];
    hy += dy[hIdx];
    visited.push({hx, hy});
    if (hx < 0 || hx >= n || hy < 0 || hy >= n) {
        return second;
    }
    if (map[hx][hy] == 2) {
        return second;
    }
    if (map[hx][hy] == 0) {
        tx = visited.front().first;
        ty = visited.front().second;
        map[tx][ty] = 0;
        visited.pop();
    }
    map[hx][hy] = 2;

    if (lIdx < l && dir[lIdx].first == second) {
        if (dir[lIdx].second == 'D') {
            hIdx = (hIdx + 1) % 4;
        } else {
            hIdx = (hIdx + 3) % 4;
        }
        lIdx++;
    }
    return move(second + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    cin >> n >> k;
    map.assign(n, vector<int>(n,0));
    map[0][0] = 2;
    visited.push({0,0});
    
    int t1,t2;
    for (int i = 0; i < k; i++) {
        cin >> t1 >> t2;
        map[t1-1][t2-1] = 1;
    }

    cin >> l;
    dir.assign(l, pair<int, char>());
    for (int i = 0; i < l; i++) {
        cin >> dir[i].first >> dir[i].second;
    }

    cout << move(1);
    return 0;
}