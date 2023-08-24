#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int num = 0;
vector< vector<int> > snail;
int n, m, k, x, y;

void fill(int t) {
    for (int i = m - t + 1; i < m + t; i++) {
        snail[m - t][i] = num;
        if (num == k) {
            x = m - t;
            y = i;
        }
        num++;
    }
    for (int i = m - t; i <= m + t; i++) {
        snail[i][m + t] = num;
        if (num == k) {
            x = i;
            y = m + t;
        }
        num++;
    }
    for (int i = m + t - 1; i > m - t; i--) {
        snail[m + t][i] = num;
        if (num == k) {
            x = m + t;
            y = i;
        }
        num++;
    }
    for (int i = m + t; i >= m - t; i--) {
        snail[i][m - t] = num;
        if (num == k) {
            x = i;
            y = m - t;
        }
        num++;
    }
}

int main () 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n >> k;
    m = n / 2;
    snail.assign(n, vector<int> (n,0));

    for (int i = 0; i <= m; i++) {
        fill(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << snail[i][j] << " ";
        }
        cout <<"\n";
    }
    cout << x+1 << " " << y+1;
    return 0;
}