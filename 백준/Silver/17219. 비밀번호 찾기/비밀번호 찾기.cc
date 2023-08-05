#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);

    int n, m;
    unordered_map<string, string> map;
    string address[100000];
    string password[100000];
    cin >> n >> m;
    string buffer;
    getline(cin, buffer);
    for (int i = 0; i < n; i++) {
        string input, t1, t2;
        getline(cin, input);
        stringstream ss(input);
        getline(ss, t1, ' ');
        getline(ss, t2, ' ');
        map[t1] = t2;
    }
    for (int i = 0; i < m; i++) {
        string temp;
        getline(cin, temp);
        cout << map[temp] << '\n';
    }
    return 0;
}