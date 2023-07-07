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

    int n;
    cin >> n;
    string buf;
    getline(cin,buf);
    
    for(int i = 0; i < n; i++) {
        string temp;
        getline(cin,temp);
        bool ok = true;
        if (temp[0] - 'A' > 5)
            ok = false;
        if (temp[0] != 'A' && temp[1] != 'A')
            ok = false;
        for(int i = 2; i < temp.size(); i++) {
            if (!ok) break;
            if (temp[i-1] != temp[i]) {
                if (temp[i-1] == 'A' && temp[i] != 'F'){
                    ok = false;
                }
                if (temp[i-1] == 'F' && temp[i] != 'C'){
                    ok = false;
                }
                if (temp[i-1] == 'C') {
                    if (temp[i] - 'A' > 5 || i != temp.size()-1) {
                        ok = false;
                    }
                }
            }
        }
        if (ok)
            cout << "Infected!\n";
        else
            cout << "Good\n";
    }
    return 0;
}