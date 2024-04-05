#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> arr;
vector<int> result;
int minLiar = 100000000;

void dfs(int idx, int liar) {
    if (liar >= minLiar) return;
    if (idx >= n) {
        if (arr[n-1] == -1) {
            minLiar = min(liar, minLiar);
            return;
        }
        if (result[n-1]) {
            if (arr[n-1] == result[0]) minLiar = min(liar, minLiar);
        }
        else {
            if (arr[n-1] != result[0]) minLiar = min(liar, minLiar);
        }
        return;
    }
    if (arr[idx-1] == -1) {
        result[idx] = 1;
        dfs(idx+1, liar);
        result[idx] = 0;
        dfs(idx+1, liar+1);
        return;
    }
    if (result[idx-1]) {
        result[idx] = arr[idx-1];
    } else {
        result[idx] = !arr[idx-1];
    }
    if (!result[idx]) liar++;
    dfs(idx+1, liar);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    cin >> n;
    arr.assign(n, 0);
    result.assign(n, 0);
    char t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t == 'H') arr[i] = 1;
        if (t == '?') arr[i] = -1;
    }
    dfs(1, 1);
    result[0] = 1;
    dfs(1, 0);
    if (minLiar == 100000000) minLiar = -1;
    cout << minLiar;
    return 0;
}