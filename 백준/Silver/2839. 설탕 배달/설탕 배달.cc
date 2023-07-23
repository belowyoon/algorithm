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

    int num;
    cin >> num;
    int result = 5000;
    int i = 0;
    while (true) {
        int temp = num - (5 * i);
        if (temp < 0)
            break;
        if (temp % 3 == 0) {
            result = min(result, i + temp / 3);
        }
        i++;
    }
    if (result == 5000)
        result = -1;
    cout << result;
    return 0;
}