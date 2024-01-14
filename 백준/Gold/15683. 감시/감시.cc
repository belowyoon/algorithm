#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> map;
vector<pair<int,int>> cctv;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
//위, 오, 아래, 왼
int result = 0;
void check(int x, int y, int i) {
    x += dx[i]; y += dy[i];
    while (x >= 0 && x < n && y >= 0 && y < m) {
        if (map[x][y] == 6) {
            break;
        }
        if (map[x][y] == 0) {
            map[x][y] = 7;
        }
        x += dx[i]; y += dy[i];
    }
    return;
}

void dfs(int depth) {
    if (depth == cctv.size()) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0) {
                    cnt++;
                }
            }
        }
        result = min(result, cnt);
        return;
    }
    int x = cctv[depth].first;
    int y = cctv[depth].second;
    vector<vector<int>> tmp;
    tmp.assign(map.begin(), map.end());
    int t = 4;
    if (map[x][y] == 2) t = 2;
    else if (map[x][y] == 5) t = 1;
    for (int i = 0; i < t; i++) {
        switch(map[x][y])
        {
        case 1:
            check(x, y, i);
            break;
        case 2:
            check(x, y, i);
            check(x, y, (i+2)%4);
            break;
        case 3:
            check(x, y, i);
            check(x, y, (i+1)%4);
            break;
        case 4:
            check(x, y, i);
            check(x, y, (i+1)%4);
            check(x, y, (i+2)%4);
            break;
        case 5:
            check(x, y, i);
            check(x, y, (i+1)%4);
            check(x, y, (i+2)%4);
            check(x, y, (i+3)%4);
            break;
        }
        dfs(depth+1);
        map.assign(tmp.begin(), tmp.end());
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    cin >> n >> m;
    map.assign(n, vector<int>(m,0));
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] >= 1 && map[i][j] <= 5) {
                cctv.push_back({i,j});
            }
            else if(map[i][j] == 0) {
                result++;
            }
        }
    }

    
    dfs(0);
    cout << result;
    return 0;
}