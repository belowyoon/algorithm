#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i-1 >= 0) map[i][j] += map[i-1][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j-1 >= 0) map[i][j] += map[i][j-1];
        }
    }

    int x1, y1, x2, y2, num;
    for (int i = 0; i < m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        num = map[x2][y2];
        if (y1-1 >= 0) num -= map[x2][y1-1];
        if (x1-1 >= 0)  num -= map[x1-1][y2];
        if (x1-1 >= 0 && y1-1 >= 0) num += map[x1-1][y1-1];
        cout << num << '\n';

    }

    return 0;
}
