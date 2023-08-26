#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> paper;
vector<vector<bool>> visited;
int n;

bool check(int x, int y, int m) {
    int color = paper[x][y];
    for (int i = x; i < x + m; i++) {
        for(int j = y; j < y + m; j++) {
            if (paper[i][j] != color) {
                return false;
            }
        }
    }
    for (int i = x; i < x + m; i++) {
        for(int j = y; j < y + m; j++) {
            visited[i][j] = true;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n;
    paper.assign(n, vector<int>(n,0));
    visited.assign(n, vector<bool>(n,false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }

    int m = n;
    int result[2] = {0};
    while(m >= 1) {
        for(int i = 0; i < n; i += m) {
            for(int j = 0; j < n; j += m) {
                if (!visited[i][j]) {
                    if (check(i,j,m)) {
                        result[paper[i][j]]++;
                    }
                }
            }
        }
        m /= 2;
    }
    cout << result[0] << '\n' << result[1];

    return 0;
}