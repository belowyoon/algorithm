#include <iostream>
#include <algorithm>
using namespace std;

int n, m, res = 0;
vector< vector<int> > map;
vector< vector<int> > dp;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int x, int y) {
	if (x == m-1 && y == n-1) {
		dp[x][y] = 1;
		return 1;
	}
	if (dp[x][y] == -1) {
		dp[x][y] = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
				continue;
			}
			if (map[nx][ny] < map[x][y]) {
				dp[x][y] += dfs(nx, ny);
			}
		}
	}
	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

	cin >> m >> n;
	map.assign(m, vector<int>(n,0));

	dp.assign(m, vector<int>(n,-1));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	cout << dfs(0,0);
    return 0;
}