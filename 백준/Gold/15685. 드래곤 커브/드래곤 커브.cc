#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
bool map[101][101];

void dragonCurve(int x, int y, int d, int g) {
    vector<int> dir;
    dir.push_back(d);
    while (g > 0) {
        int size = dir.size();
        for (int i = size - 1; i >= 0; i--) {
            dir.push_back((dir[i] + 1) % 4);
        }
        g--;
    }
    map[y][x] = true;
    for (int i = 0; i < dir.size(); i++) {
        x += dx[dir[i]];
        y += dy[dir[i]];
        map[y][x] = true;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    int x, y, d, g;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> d >> g;
        dragonCurve(x, y, d, g);
    }
    int res = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if ( i+1 > 100 || j+1 > 100) {
                continue;
            }
            if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) {
                res++;
            }
        }
    }
    cout << res;
    return 0;
}