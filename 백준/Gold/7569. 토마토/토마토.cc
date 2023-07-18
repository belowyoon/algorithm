#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    int m, n, h;
    int map[100][100][100] = {0};
    int t;
    queue<vector<int>> q;

    cin >> m >> n >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> t;
                if (t == 1) {
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(k);
                    q.push(temp);
                }
                map[i][j][k] = t;
            }
        }
    }

    while (!q.empty())
    {
        vector<int> temp = q.front();
        q.pop();
        int i = temp[0];
        int j = temp[1];
        int k = temp[2];

        if (map[i][j][k] != -1) {
            if (i-1 >= 0) {
                if (map[i-1][j][k] == 0) {
                    temp[0] = i-1;
                    q.push(temp);
                    temp[0] = i;
                    map[i-1][j][k] = map[i][j][k] + 1;
                }
            }
            if (i+1 < h) {
                if (map[i+1][j][k] == 0) {
                    temp[0] = i+1;
                    q.push(temp);
                    temp[0] = i;
                    map[i+1][j][k] = map[i][j][k] + 1;
                }
            }
            if (j-1 >= 0) {
                if (map[i][j-1][k] == 0) {
                    temp[1] = j-1;
                    q.push(temp);
                    temp[1] = j;
                    map[i][j-1][k] = map[i][j][k] + 1;
                }
            }
            if (j+1 < n) {
                if (map[i][j+1][k] == 0) {
                    temp[1] = j+1;
                    q.push(temp);
                    temp[1] = j;
                    map[i][j+1][k] = map[i][j][k] + 1;
                }
            }
            if (k-1 >= 0) {
                if (map[i][j][k-1] == 0) {
                    temp[2] = k-1;
                    q.push(temp);
                    temp[2] = k;
                    map[i][j][k-1] = map[i][j][k] + 1;
                }
            }
            if (k+1 < m) {
                 if (map[i][j][k+1] == 0) {
                    temp[2] = k+1;
                    q.push(temp);
                    temp[2] = k;
                    map[i][j][k+1]= map[i][j][k] + 1;
                }
            }
        } 
    }
    int result = -1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (map[i][j][k] == 0) {
                    cout << "-1" << '\n';
                    return 0;
                }
                result = max(result,  map[i][j][k]);
            }
        }
    }
    cout << result-1;

    return 0;
}