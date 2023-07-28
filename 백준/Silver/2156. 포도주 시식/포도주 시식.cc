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
    int grape[10000] = {0};
    int drink[10000] = {0};
    for (int i = 0; i < n; i++) {
        cin >> grape[i];
    }
    drink[0] = grape[0];
    drink[1] = grape[0]+grape[1];
    drink[2] = max(drink[1] , max(grape[0]+grape[2], grape[1]+grape[2]));
    for (int i = 3; i < n; i++) {
        drink[i] = max(drink[i-3] + grape[i-1] + grape[i], drink[i-2] + grape[i]);
        drink[i] = max(drink[i], drink[i-1]);
    }
    cout << drink[n-1];
    return 0;
}