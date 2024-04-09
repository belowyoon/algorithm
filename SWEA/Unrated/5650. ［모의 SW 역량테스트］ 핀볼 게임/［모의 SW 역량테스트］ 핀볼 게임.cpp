#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<vector<int> > map;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int changeD[6][5] = {
    {1, 0, 3, 2},
    {1, 3, 0, 2},
    {1, 2, 3, 0},
    {2, 0, 3, 1},
    {3, 0, 1, 2},
    {1, 0, 3, 2}
};

vector<vector<pair<int, int> > >warmhole;

int move(int sx, int sy, int d) {
    int score = 0;
    int x = sx, y = sy;
    while (true) {
        x += dx[d];
        y += dy[d];
        if (x < 0 || x >= n || y < 0 || y >= n) {
            score++;
            d = changeD[0][d];
            continue;
        }
        int point = map[x][y];
        if (point == -1 || (x == sx && y == sy)) {
            break;
        }
        if (point >= 1 && point <= 5) {
            score++;
            d = changeD[point][d];
        }
        else if (point >= 6 && point <= 10) {
            for (int i = 0; i < 2; i++) {
                if (!(warmhole[point-6][i].first == x && warmhole[point-6][i].second == y)) {
                    x = warmhole[point-6][i].first;
                    y = warmhole[point-6][i].second;
                    break;
                }
            }
        }
    }
    return score;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t, cnt = 1;
    cin >> t;

    while(t--) {
        cin >> n;
        warmhole.assign(5, vector<pair<int, int> >());

        map.assign(n, vector<int>(n, 0));
        vector<pair<int, int> > emptys;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
                if (map[i][j] == 0) emptys.push_back(make_pair(i,j));
                if (map[i][j] >= 6 && map[i][j] <= 10) warmhole[map[i][j]-6].push_back(make_pair(i,j));
            }
        }
        int result = 0;
        for (int i = 0; i < emptys.size(); i++) {
            for (int j = 0; j < 4; j++) {
                result = max(result, move(emptys[i].first, emptys[i].second, j));
            }
        }
        cout << '#' << cnt << " " << result << '\n';
        cnt++;
    }
    return 0;
}