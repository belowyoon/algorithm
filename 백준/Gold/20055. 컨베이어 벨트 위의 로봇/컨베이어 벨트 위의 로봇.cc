#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, k, d = 0;
vector<int> cb;
vector<int> r;

void moveCB() {
    int prev = cb[2 * n - 1];
    int temp;
    for (int i = 0; i < 2 * n; i++){
        temp = cb[i];
        cb[i] = prev;
        prev = temp;
    }
    prev = r[0];
    r[0] = 0;
    for (int i = 1; i < n; i++) {
        temp = r[i];
        r[i] = prev;
        prev = temp;
        if (i == n-1 && r[i] > 0) {
            r[i] = 0;
        }
    }
}

void moveRobot() {
    for (int i = n-1; i > 0; i--){
        if (cb[i] > 0 && r[i] == 0 && r[i-1] == 1) {
            cb[i]--;
            r[i]++;
            r[i-1]--;
            if (cb[i] == 0) {
                d++;
            }
        }
        if (i == n-1 && r[i] > 0) {
            r[i] = 0;
        }
    }
}

void putRobot() {
    if (cb[0] > 0) {
        r[0]++;
        cb[0]--;
        if (cb[0] == 0) {
            d++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n >> k;
    cb.assign(n*2,0);
    r.assign(n*2,0);
    for (int i = 0; i < n * 2; i++) {
        cin >> cb[i];
    }
   
    int cnt = 0;
    while(d < k) {
        moveCB();
        moveRobot();
        putRobot();
        cnt++;
    }
    cout << cnt;
}