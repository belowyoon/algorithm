#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

string change(string str) {
    string res;
    if (str[str.size() - 1] == 'K'){
        res.push_back('5');
    } else {
        res.push_back('1');
    }
    for (int i = 0; i < str.size() - 1; i++) {
        res.push_back('0');
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    string str;
    cin >> str;
    vector<string> num1;
    vector<string> num2;
    int index1 = 0, index2 = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'K') {
            num1.push_back(str.substr(index1, i - index1 + 1));
            index1 = i+1;
            if (i-index2 != 0) {
                num2.push_back(str.substr(index2, i - index2));
            }
            num2.push_back("K");
            index2 = i+1;
        }
    }
    while (index1 < str.size()) {
        num1.push_back("M");
        index1++;
    }
    if (index2 < str.size()) {
        num2.push_back(str.substr(index2));
    }
    for (int i = 0; i < num1.size(); i++) {
        cout << change(num1[i]);
    }
    cout << '\n';
    for (int i = 0; i < num2.size(); i++) {
        cout << change(num2[i]);
    }
}