#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> snowball;

int smallest(int x, int y) {
    int cmp = snowball[x] + snowball[y];
    int result = 2000000001;
    int s = x + 1, e = y - 1;
    while (s < e) {
        //cout << x << y << s << e << '\n';
        result = min(result, abs(cmp - (snowball[s] + snowball[e])));
        if (cmp > snowball[s] + snowball[e]) {
            s++;
        } else if (cmp < snowball[s] + snowball[e]) {
            e--;
        } else {
            return 0;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n, result = 2000000001;
    cin >> n;
    snowball.assign(n, 0);

    for (int i = 0; i < n; i++){
        cin >> snowball[i];
    }
    sort(snowball.begin(), snowball.end());
    for (int i = 0; i < n; i++){
        for (int j = n-1; j > i; j--){
            result = min(result, smallest(i, j));
        }
    }
    cout << result;
    return 0;
}
