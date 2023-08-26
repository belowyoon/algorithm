#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> num;
    int n;
    cin >> n;
    num.assign(n,0);

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    for (int i = 0; i < n; i++) {
        cout << num[i] << '\n';
    }

    return 0;
}