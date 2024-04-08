#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> map;
vector<pair<int, int>> virus;
vector<pair<int, int>> emptys;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

void resetMap() {
    for (int i = 0; i < emptys.size(); i++) {
        map[emptys[i].first][emptys[i].second] = 0;
    }
    return;
}

int bfs() {
    int change = 0;
    for (int i = 0; i < virus.size(); i++) {
        q.push({virus[i].first, virus[i].second});
    }
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (map[nx][ny] == 0) {
                q.push({nx, ny});
                map[nx][ny] = 2;
                change++;
            }
        }
    }
    return change;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    cin >> n >> m;
    map.assign(n, vector<int>(m,0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (!map[i][j]) emptys.push_back({i,j});
            if (map[i][j] == 2) virus.push_back({i,j});
        }
    }

    int result = 0;
    for (int i = 0; i < emptys.size(); i++) {
        for (int j = i + 1; j < emptys.size(); j++) {
            for (int k = j + 1; k < emptys.size(); k++) {
                map[emptys[i].first][emptys[i].second] = 3;
                map[emptys[j].first][emptys[j].second] = 3;
                map[emptys[k].first][emptys[k].second] = 3;
                result = max(result, (int)emptys.size() - bfs() - 3);
                resetMap();
            }
        }
    }
    cout << result;

    return 0;
}