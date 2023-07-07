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

    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        string game;
        int k;
        cin >> game;
        cin >> k;
        int s = 10001;
        int l = -1;
        vector<int> arr[27];
        for (int j = 0; j < game.size(); j++) {
            arr[game[j]-'a'].push_back(j);
        }
        for (int j = 0; j < 27; j++) {
            if (k == 1) {
                l = 1;
                s = 1;
                break;
            }
            int num = arr[j].size();
            if (num >= k) {
                char c = j + 'a';
                for (int z = 0; z < num - k + 1; z++){
                    s = min(s, arr[j][z+k-1] - arr[j][z] + 1);
                    l = max(l, arr[j][z+k-1] - arr[j][z] + 1);
                }
            }
        }
        if (l == -1) {
            cout << -1 << "\n";
        }
        else {
            cout << s << " " << l << "\n";
        }
    }
    return 0;
}
