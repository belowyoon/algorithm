#include <iostream>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> map;

int calc(int x, int y, int d1, int d2) {
    
    vector<vector<int>> temp;
    temp.assign(n + 1, vector<int>(n + 1, 0));
    int elec[5] = {0};

    for (int i = 0; i <= d1; i++) {
        temp[x + i][y - i] = 5;
        temp[x + d2 + i][y + d2 - i] = 5;
    }
    for (int i = 0; i <= d2; i++) {
        temp[x + i][y + i] = 5;
        temp[x + d1 + i][y - d1 + i] = 5;
    }

    for (int r = 1; r <= n; r++) {
        bool flag = false;
        for (int c = 1; c <= n; c++) {
            if (temp[r][c] == 5 && r > x && r < x + d1 + d2) {
                flag = !flag;
            }
            if (flag) {
                temp[r][c] = 5;
            }
            if (r < x + d1 && c <= y && temp[r][c] == 0) {
                elec[0] += map[r][c];
            } else if (r <= x + d2 && y < c && temp[r][c] == 0) {
                elec[1] += map[r][c]; 
            } else if (x + d1 <= r && c < y - d1 + d2 && temp[r][c] == 0) {
                elec[2] += map[r][c];
            } else if (x + d2 < r && y - d1 + d2 <= c && temp[r][c] == 0) {
                elec[3] += map[r][c]; 
            } else {
                elec[4] += map[r][c];
            }
        }
    }
    return *max_element(elec, elec+5) - *min_element(elec, elec+5);
}

bool satisfy(int x, int y, int d1, int d2) {
    if (d1 >= 1 && d2 >= 1) {
        if (x >= 1 && x < x + d1 + d2 && x + d1 + d2 <= n) {
            if (1 <= y - d1 && y < y + d2 && y - d1 < y && y + d2 <= n) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n ;
    map.assign(n+1, vector<int>(n+1, 0));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }
    
    int result = 1000000000;
    for (int x = 1; x <= n; x++){
        for (int y = 1; y <= n; y++){
            for (int d1 = 1; d1 <= n; d1++) {
				for (int d2 = 1; d2 <= n; d2++) {
					if (satisfy(x, y, d1, d2)) {
						result = min(result, calc(x, y, d1, d2));
					}
				}
			}
        }
    }
    cout << result;
    return 0;
}