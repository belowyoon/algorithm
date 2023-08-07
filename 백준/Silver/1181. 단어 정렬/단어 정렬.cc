#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

bool compare ( string a,  string b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);

    int n;
    vector<string> arr;

    cin >> n;
    arr.assign(n, "");

    string temp;
    getline(cin, temp);

    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }

    sort(arr.begin(), arr.end(), compare);

    cout << arr[0] << '\n';

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i-1]) {
            cout << arr[i] << '\n';
        }
    }

    return 0;
}