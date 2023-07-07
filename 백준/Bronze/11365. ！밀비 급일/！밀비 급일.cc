#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    
    int n;
    string c;

    while(true) {
        getline(cin, c);
        if (c == "END")
            break;
        reverse(c.begin(), c.end());
        cout << c << "\n";
    }

    return 0;
}