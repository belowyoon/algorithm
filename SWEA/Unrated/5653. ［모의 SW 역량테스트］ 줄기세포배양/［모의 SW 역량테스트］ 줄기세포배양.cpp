#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
vector<vector<int > > map;
vector<vector<int > > state;
int result;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int checkAlive() {
    int alive = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] > 0) {
                alive++;
            }
        }
    }
    return alive;
}

void expandMap() {
    vector<vector<int > > newMap(n + 2, vector<int>(m+2, 0));
    vector<vector<int > > newState(n + 2, vector<int>(m+2, 0));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            newMap[i][j] = map[i-1][j-1];
            newState[i][j] = state[i-1][j-1];
        }
    }
    n += 2;
    m += 2;
    map.assign(n, vector<int>(m, 0));
    state.assign(n, vector<int>(m, 0));
    map = newMap;
    state = newState;
    return;
}

bool spread(int x, int y) {
    bool flag = false;
    int life = map[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            expandMap();
            x++; y++;
            flag = true;
            i--; continue;
        }
        if (map[nx][ny] == 0 || (map[nx][ny] < life && state[nx][ny] == -1)) {
            map[nx][ny] = life;
            state[nx][ny] = -1;
        }
    }
    return flag;
}

void changeState() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(map[i][j] > 0) {
                state[i][j]++;
                if (state[i][j] == map[i][j] * 2) map[i][j] = -1;
            }
        }
    }
    return;
}

void lookForSpread() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(state[i][j] == map[i][j] && map[i][j] > 0) {
                if (spread(i, j)) {
                    i++;
                    j++;
                }
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t, cnt = 1;
    cin >> t;

    while(t--) {
        cin >> n >> m >> k;
        map.assign(n, vector<int>(m, 0));
        state.assign(n, vector<int>(m, 0));
        int blocks = 0;
        result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
            }
        }
        for (int i = 1; i <= k; i++) {
            lookForSpread();
            changeState();
        }
        cout << '#' << cnt << " " << checkAlive() << '\n';
        cnt++;
    }
    return 0;
}