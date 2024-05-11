#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<char>> map;
vector<bool> alpha;

int r, c;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int result = 0;

void dfs(int x, int y, int depth) {
    result = max(result, depth);
    for (int j = 0; j < 4; j++) {
        int nx = x + dx[j], ny = y + dy[j];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c || alpha[map[nx][ny] - 'A']) {
            continue;
        }
        alpha[map[nx][ny] - 'A'] = true;
        dfs(nx, ny, depth+1);
        alpha[map[nx][ny] - 'A'] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> r >> c;
    map.assign(r, vector<char>(c, 0));
    alpha.assign(26, false);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }

    alpha[map[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << result;

    return 0;
}
