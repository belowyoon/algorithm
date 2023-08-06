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

    vector<int> num;
    vector<string> noMinus;
    string formula;
    
    getline(cin, formula);
    
    stringstream ss(formula);
    string temp;
    while(getline(ss, temp, '-')) {
        noMinus.push_back(temp);
    }

    for(int i = 0; i < noMinus.size(); i++) {
        stringstream ss2(noMinus[i]);
        int p = 0;
        while(getline(ss2, temp, '+')) {
            p += stoi(temp);
        }
        num.push_back(p);
    }
        
    int result = num[0];
    for (int i = 1; i < num.size(); i++) {
        result -= num[i];
    }
    cout << result;
    return 0;
}