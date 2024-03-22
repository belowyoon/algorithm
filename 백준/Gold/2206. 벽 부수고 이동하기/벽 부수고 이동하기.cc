#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<char>> map;
bool visited[1001][1001][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

struct Node {
    int x;
    int y;
    bool wall;
};

int cal(){
    queue<Node> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1;
    int depth = 0;
    
    while (!q.empty()){
        int size = q.size();
        depth++;
        for (int i = 0; i < size; i++){
            Node node = q.front();
            q.pop();

            if (node.x == n-1 && node.y == m-1) return depth;

            for (int j = 0; j < 4; j++){
                int nx = node.x + dx[j];
                int ny = node.y + dy[j];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                
                if (map[nx][ny] == '0' && !visited[nx][ny][node.wall]){
                    visited[nx][ny][node.wall] = true;
                    q.push({nx, ny, node.wall});
                } 
                if (map[nx][ny] == '1' && node.wall == 0) {
                    visited[nx][ny][1] = true;
                    q.push({nx, ny, 1});
                }
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n >> m;

    map.assign(n, vector<char>(m, '0'));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            char t;
            cin >> t;
            map[i][j] = t;
        }
    }
    
    cout << cal();
    return 0;
}