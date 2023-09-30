#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> map;
int n, result = 0;

void dfs(int direction, int x, int y) {
    if (x == n-1 && y == n-1) {
        if (direction == 2 && (map[x-1][y] == 1 || map[x][y-1] == 1)) {
            return;
        }
        result++;
        return;
    }
    if (x >= n || y >= n) {
        return;
    }
    if (map[x][y] == 1 || (direction == 2 && (map[x-1][y] == 1 || map[x][y-1] == 1))) {
        return;
    }
    if (direction == 0) {
        dfs(0,x,y+1);
    } else if (direction == 1) {
        dfs(1,x+1,y);
    } else if (direction == 2) {
        dfs(0,x,y+1);
        dfs(1,x+1,y);
    }
    dfs(2, x+1, y+1);
    return;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    map.assign(n, vector<int> (n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    if (map[n-1][n-1] != 1) {
        dfs(0,0,1);
    }
    cout << result;
    return 0;
}