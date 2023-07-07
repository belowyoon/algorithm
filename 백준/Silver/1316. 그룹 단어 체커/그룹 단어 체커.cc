#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    int n, result = 0;
    cin >> n;
    string buff;
    getline(cin,buff);

    for(int i = 0; i < n; i++) {
        string temp;
        int map[30] = {0};
        getline(cin, temp);
        map[temp[0]-'a']++;

        for (int j = 1; j < temp.size(); j++) {
            if (temp[j] != temp[j-1]) {
                if (map[temp[j] - 'a'] > 0) {
                    result++;
                    break;
                } 
                map[temp[j] - 'a']++;
            }
        }
    }

    cout << n - result;

    return 0;
}
