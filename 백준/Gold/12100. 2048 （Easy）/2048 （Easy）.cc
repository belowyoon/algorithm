#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int result = 0;
vector<vector<int>> map;

void moveMap(int d) {
    queue<int> q;
    if (d == 0) {
        //up
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[j][i] != 0) {
                    q.push(map[j][i]);
                }
            }
            if (!q.empty()) {
                map[0][i] = q.front();
                q.pop();
            }
            bool flag = false;
            for (int j = 1; j < n; j++) {
                if (!q.empty()) {
                    int t = q.front();
                    q.pop();
                    if (t == map[j-1][i] && !flag) {
                        map[j-1][i] *= 2;
                        j--;
                        flag = true;
                        continue;
                    }
                    else {
                        map[j][i] = t;
                    }
                } else {
                    map[j][i] = 0;
                }
                flag = false;
            }
        }
    }
    else if (d == 1) {
        //down
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (map[j][i] != 0) {
                    q.push(map[j][i]);
                }
            }
             if (!q.empty()) {
                map[n - 1][i] = q.front();
                q.pop();
            }
            bool flag = false;
            for (int j = n - 2; j >= 0; j--) {
                if (!q.empty()) {
                    int t = q.front();
                    q.pop();
                    if (t == map[j+1][i] && !flag) {
                        map[j+1][i] *= 2;
                        j++;
                        flag = true;
                        continue;
                    }
                    else {
                        map[j][i] = t;
                    }
                } else {
                    map[j][i] = 0;
                }
                flag = false;
            }
        }
    } 
    else if (d == 2) {
        //right
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (map[i][j] != 0) {
                    q.push(map[i][j]);
                }
            }
            if (!q.empty()) {
                map[i][n-1] = q.front();
                q.pop();
            }
            bool flag = false;
            for (int j = n - 2; j >= 0; j--) {
                if (!q.empty()) {
                    int t = q.front();
                    q.pop();
                    if (t == map[i][j+1] && !flag) {
                        map[i][j+1] *= 2;
                        j++;
                        flag = true;
                        continue;
                    }
                    else {
                        map[i][j] = t;
                    }
                } else {
                    map[i][j] = 0;
                }
                flag = false;
            }
        }
    } 
    else if (d == 3) {
        //left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] != 0) {
                    q.push(map[i][j]);
                }
            }
            if (!q.empty()) {
                map[i][0] = q.front();
                q.pop();
            }
            bool flag = false;
            for (int j = 1; j < n; j++) {
                if (!q.empty()) {
                    int t = q.front();
                    q.pop();
                    if (t == map[i][j-1] && !flag) {
                        map[i][j-1] *= 2;
                        j--;
                        flag = true;
                        continue;
                    }
                    else {
                        map[i][j] = t;
                    }
                } else {
                    map[i][j] = 0;
                }
                flag = false;
            }
        }
    }
    return;
}

void dfs(int depth) {
    if(depth == 5) {
        int now = 0;
        for (int i = 0; i < n; i++) {  
            for (int j = 0; j < n; j++) {
                now = max(now, map[i][j]);
            }
        }
        result = max(now, result);
        return;
    }
    vector<vector<int>> tmp;
    tmp.assign(map.begin(), map.end());
    for (int i = 0; i < 4; i++) {
        moveMap(i);
        dfs(depth+1);
        map.assign(tmp.begin(), tmp.end());
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    cin >> n;
    map.assign(n, vector<int>(n,0));
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    dfs(0);
    cout << result;
    return 0;
}