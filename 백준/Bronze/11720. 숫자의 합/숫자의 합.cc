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
    char c;

    cin >> n;

    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> c;
        sum += c - '0';
        
    }
    cout << sum;

    return 0;
}