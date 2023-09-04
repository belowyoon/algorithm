#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<char>> stars;
int n;
void starPrint(int t) {
    int s = n * 4 - 3;
    t = t * 2;
    for(int i = t; i < t + s; i++) {
        stars[i][t] = '*';
        stars[i][t+s - 1] = '*';
        stars[t][i] = '*';
        stars[t+s -1][i] = '*';
    }
    n--;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n;

    int m = n * 4 - 3;
    stars.assign(m, vector<char>(m, ' '));

    int size = n;
    for(int i = 0; i < size; i++) {
        starPrint(i);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << stars[i][j];
        }
        cout << '\n';
    }
  
    return 0;
}