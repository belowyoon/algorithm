#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    int a, t, b;
    cin >> a >> t >> b;
    int cmp, result = -1, cnt = 0, n = 2;
    while (true) {
        for (int i = 0; i < 4 + n * 2; i++) {
            if (i == 0 || i == 2) {
                cmp = 0;
            }
            else if (i == 1 || i == 3) {
                cmp = 1;
            } else {
                if(i <= 3 + n) {
                    cmp = 0;
                } else {
                    cmp = 1;
                }
            }
            result++;
            if(cmp == b)
                cnt++;
            if (cnt == t)
                break;
        }
        if (cnt == t)
            break;
        n++;
    }

    cout << result % a;
    return 0;
}
