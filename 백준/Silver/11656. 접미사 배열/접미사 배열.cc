#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    string s;
    getline(cin, s);
    int n = s.length();
    vector<string> suffix;

    for(int i = 0; i < n; i++) {
        suffix.push_back(s.substr(i, n-i));
    }
    sort(suffix.begin(), suffix.end());
    for(int i = 0; i < n; i++) {
        cout << suffix[i] << '\n';
    }

    return 0;
}