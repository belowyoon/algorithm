#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool gear[4][8];
bool visited[4];

void turn(int k, int d){
    visited[k] = true;
    if (k-1 >= 0 && !visited[k-1]) {
        if (gear[k][6] != gear[k-1][2]) {
            turn(k - 1, d * -1);
        }
    }
    if (k+1 < 4 && !visited[k+1]) {
        if (gear[k][2] != gear[k+1][6]) {
            turn(k + 1, d * -1);
        }
    }
    int prev = gear[k][0], idx = 0, tmp;
    for (int i = 0; i < 8; i++) {
        idx = (idx + d + 8) % 8;
        tmp = gear[k][idx];
        gear[k][idx] = prev;
        prev = tmp;
    }
    return;
}

int calc() {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        if (gear[i][0]) {
            cnt += pow(2, i);
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    string s;
    for (int i = 0; i < 4; i++) {   
        getline(cin, s);
        for (int j = 0; j < 8; j++) {
            gear[i][j] = s[j] - '0';
        }
    }

    int n;
    cin >> n;

    int k, d;
    for (int i = 0 ; i < n; i++) {
        cin >> k >> d;
        fill(visited, visited + 4, false);
        turn(k - 1, d);
    }

    cout << calc();

    return 0;
}