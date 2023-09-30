#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    vector<vector<int>> triangle;
    int n, result = -1;
    cin >> n;
    triangle.assign(n, vector<int> (n,-1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                triangle[i][j] += triangle[i-1][j];
            } else if (j == i) {
                triangle[i][j] += triangle[i-1][j-1];
            } else {
                triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        result = max(result, triangle[n-1][i]);
    }
    
    cout << result;

    return 0;
}