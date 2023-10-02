#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<char>> stars;
int n, m;

void insertStars(int x, int y, int k) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return;
    }
    stars[x][y] = '*';
    stars[x+1][y-1] = '*';
    stars[x+1][y+1] = '*';
    for (int i = y - 2; i <= y + 2; i++) {
        stars[x+2][i] = '*';
    }
    while (k != 0) {
        insertStars(x + 3 * k, y - 3 * k, k / 2);
        insertStars(x + 3 * k, y + 3 * k, k / 2);
        k /= 2;
    }
    return;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n;
    m = n * 2 - 1;
    stars.assign(n, vector<char>(m, ' '));

    insertStars(0, m / 2, n / 6);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << stars[i][j];
        }
        cout << '\n';
    }
    return 0;
}