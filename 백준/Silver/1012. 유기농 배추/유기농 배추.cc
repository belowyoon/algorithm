#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int m, n;
vector<vector<bool>> farm;

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return;
    }
    if(farm[x][y] == 0)
        return;
    farm[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        dfs(x+dx[i], y+dy[i]);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    while (t > 0) {
        int k;
        cin >> m >> n >> k;
        farm.assign(n, vector<bool>(m,0));
        
        int t1, t2;
        for (int i = 0; i < k; i++) {
            cin >> t1 >> t2;
            farm[t2][t1] = 1;
        }
        
        int worm = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (farm[i][j] == 1) {
                    worm++;
                    dfs(i,j);
                }
            }
        }
        cout << worm << '\n';
        t--;
    }
    return 0;
}