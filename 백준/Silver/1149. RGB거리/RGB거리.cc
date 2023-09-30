#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    vector<vector<int>> color;
    int n, result = 10000000;
    cin >> n;
    color.assign(n, vector<int> (3, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> color[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        color[i][0] += min(color[i-1][1], color[i-1][2]);
        color[i][1] += min(color[i-1][0], color[i-1][2]);
        color[i][2] += min(color[i-1][0], color[i-1][1]);
    }
    for (int i = 0; i < 3; i++) {
        result = min(result, color[n-1][i]);
    }

    cout << result;

    return 0;
}