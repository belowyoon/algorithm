#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int>> cave;
vector<vector<int>> dp;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int result;

void bfs() {
    queue<pair<int, int>> q;
    dp[0][0] = cave[0][0];
    q.push({0, 0});
    while (!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (dp[x][y] + cave[nx][ny] < dp[nx][ny]) {
                dp[nx][ny] = dp[x][y] + cave[nx][ny];
                q.push({nx, ny});
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
        dp.assign(n, vector<int>(n, 1000000000));
        result = 1000000000;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> cave[i][j];
            }
        }
        bfs();
        cout << "Problem " << t << ": " << dp[n-1][n-1] << '\n';
    }
    return 0;
}