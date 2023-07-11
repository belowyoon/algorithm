#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int r, c, n;
vector<vector<char>> now;
vector<vector<char>> all;

void dfs(int i, int j) {
    if (i < 0 || i >= r  || j < 0 || j >= c)
        return;
    all[i][j] = '.';
}
void bomb() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++){
            if (now[i][j] == 'O') {
                dfs(i, j);
                dfs(i-1, j);
                dfs(i+1, j);
                dfs(i, j-1);
                dfs(i, j+1);
            }
        }
    }
    now = all;
    all.assign(r,vector<char>(c,'O'));
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    cin >> r >> c >> n;
    now.assign(r,vector<char>(c,'O'));
    all.assign(r,vector<char>(c,'O'));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++){
            char t;
            cin >> t;
            if (t == '.') {
                now[i][j] = '.';
            } 
        }
    }

    if (n == 1) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++){
                cout << now[i][j];
            }
            cout << '\n';
        }
    }
    else if (n % 2 == 0) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++){
                cout << all[i][j];
            }
            cout << '\n';
        }
    } else {
        if (n % 4 == 3) {
            bomb();
        } else if (n % 4 == 1) {
            bomb();
            bomb();
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++){
                cout << now[i][j];
            }
            cout << '\n';
        }
    } 
    return 0;
}
