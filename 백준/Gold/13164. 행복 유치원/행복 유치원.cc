#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);

    int n, k;
    int children[300000] = {0};
    int diff[300000];

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> children[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        diff[i] = children[i+1] - children[i];
    }
    sort(diff, diff+n-1);
    int result = 0;
    for (int i = 0; i < n-k; i++)
    {
        result += diff[i];
    }
    cout << result;

    return 0;
}
