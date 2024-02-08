#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000

vector<char> res;
string str;

void printRes() {
    for (int i = 0; i < res.size(); i++) {
        if (res[i] != ' ') {
            cout << res[i];
        }
    }
    cout << '\n';
}

void getChar(int s) {
    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
    for (int i = s; i < str.size(); i++) {
        if (res[i] == ' ') {  
            pq.push({str[i], i});
        }
    }
    while(!pq.empty()) {
        char temp = pq.top().first;
        char index = pq.top().second;
        pq.pop();
        if (res[index] != ' ') {
            continue;
        }
        res[index] = temp;
        printRes();
        getChar(index + 1);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    getline(cin, str);
    res.assign(str.size(),' ');

    getChar(0);
    return 0;
}