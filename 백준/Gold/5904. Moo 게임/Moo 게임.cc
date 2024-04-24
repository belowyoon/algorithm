#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    int len = 3;
    int mid = 3;

    while (n > len) {
        mid++;
        len = len * 2 + mid;
    }

    while(true) {
        int prev = (len-mid) / 2;

        if (n <= prev) {
            mid--;
            len = prev;
        } else if (n > prev + mid) {
            n -= prev + mid;
            mid--;
            len = prev;
        } else {
            n -= prev;
            break;
        }
    }
    if (n == 1) cout << "m";
    else cout << "o";
    return 0;
}
