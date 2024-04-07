#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    int n, b, c;
    cin >> n;
    vector<int> students(n,0);
    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }
    cin >> b >> c;
    long long result = 0;
    for (int i = 0; i < n; i++) {
        long long temp = students[i] - b;
        result++;
        if (temp > 0) result += temp / c + (temp % c > 0);
    }
    cout << result;
    return 0;
}