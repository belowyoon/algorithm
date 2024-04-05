#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int>> cave;
vector<vector<int>> rupee;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int result;

void dij() {
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({-cave[0][0], {0, 0}});
    while (!pq.empty()){
        int r = -pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            int nr  = r + cave[nx][ny];
            if (nr < rupee[nx][ny]) {
                rupee[nx][ny] = nr;
                pq.push({-nr, {nx, ny}});
            }
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    int t = 0;
    while (true) {
        cin >> n;
        if (n == 0) break;
        t++;
        cave.assign(n, vector<int>(n, 0));
        rupee.assign(n, vector<int>(n, 1000000000));
        result = 1000000000;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> cave[i][j];
            }
        }
        dij();
        cout << "Problem " << t << ": " << rupee[n-1][n-1] << '\n';
    }
    return 0;
}