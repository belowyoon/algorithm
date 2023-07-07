#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check(string test) {
    int l = 0;
    int r = test.size()-1;
    while(l < r) {
        if (test[l] == ' ') 
        {
            l++;
            continue;
        } 
        else if (test[r] == ' ')
        {
            r--;
            continue;
        }
        if (test[l] != test[r]) {
            return l;
        }
        l++;
        r--;
    }
    return -1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string test;
        cin >> test;
        int flag = 0;
        int l = 0;
        int r = test.size()-1;
        int res = check(test);
        if (res == -1) {
            cout << "0\n";
        } else {
            string test2 = test;
            test[res] = ' ';
            test2[r-res] = ' ';
            if (check(test) == -1 || check(test2) == -1){
                cout << "1\n";
            } else {
                cout << "2\n";
            }
        }
    }
    return 0;
}
