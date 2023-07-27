#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    int stairs[300] = {0};
    int up[300] = {0};
    pair<int,bool> two;
    for (int i = 0; i < n; i++) {
        cin >> stairs[i];
    }
    if (n==1) {
        cout << stairs[0];
        return 0;
    }
    up[0] = stairs[0];
    up[1] = stairs[0]+stairs[1];
    up[2] = max(stairs[0]+stairs[2], stairs[1]+stairs[2]);
    for (int i = 3; i < n; i++) {
        up[i] = max(up[i-3] + stairs[i-1] + stairs[i], up[i-2] + stairs[i]);
    }
    cout << up[n-1];
    return 0;
}