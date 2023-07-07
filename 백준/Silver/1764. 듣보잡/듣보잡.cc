#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    string buf;
    getline(cin,buf);
    unordered_set<string> s;
    vector<string> result;
    
    for(int i = 0; i < n; i++) {
        string temp;
        getline(cin,temp);
        s.insert(temp);
    }
    for(int i = 0; i < m; i++) {
        string temp;
        getline(cin,temp);
        if (s.find(temp) != s.end())
            result.push_back(temp);
    }
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
    return 0;
}
