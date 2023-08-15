#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int m, n;
    vector<vector<int>> box;
    cin >> m >> n;
    box.assign(n, vector<int>(m,0));

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    queue<pair <int, int>> q;
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> box[i][j];
            if(box[i][j] == 1) {
                q.push({i,j});
            }
        }
    }

    while(!q.empty()) {
        int size = q.size();
        count++;
        for(int i = 0; i < size; i++) {
            pair<int, int> temp = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int x = temp.first + dx[j];
                int y = temp.second + dy[j];
                if (x < 0 || x >= n || y < 0 || y >= m) {
                    continue;
                }
                if (box[x][y] == 0) {
                    q.push({x,y});
                    box[x][y] = count;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (box[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << count - 1;
    return 0;
}