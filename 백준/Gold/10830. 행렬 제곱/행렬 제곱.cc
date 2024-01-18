#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long b;
vector<vector<long long>> vecs;
vector<vector<long long>> res;
vector<vector<long long>> t;

void multiVecs(vector<vector<long long>> &a, vector<vector<long long>> &b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            t[i][j] = 0;
            for (int k = 0; k < n; k++) {
                t[i][j] += (a[i][k] * b[k][j]);
            }
            t[i][j] %= 1000;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = t[i][j];
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n >> b;
    vecs.assign(n, vector<long long>(n, 0));
    res.assign(n, vector<long long>(n, 0));
    t.assign(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> vecs[i][j];
        }
        res[i][i] = 1;
    }
    while(b > 0) {
        if (b % 2 == 1) {
            multiVecs(res, vecs);
        }
        multiVecs(vecs, vecs);
        b /= 2;
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << res[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}