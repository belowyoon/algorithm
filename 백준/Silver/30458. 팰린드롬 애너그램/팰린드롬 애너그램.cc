#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n;
    char tmp; 
    int arr[26];
    fill(arr, arr+26, 0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        if (i == n/2 && n%2 == 1)
            continue;
        arr[tmp - 'a']++;
    }
    bool flag = true;
    for (int i = 0; i < 26; i++){
        if (arr[i] % 2 == 1) {
            flag = false;
        } 
    }
    cout << (flag ? "Yes" : "No");

    return 0;
}