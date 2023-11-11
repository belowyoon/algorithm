#include <iostream>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> points;
vector<int> t1;
vector<int> t2;
int s1, s2;

int cal(int prev, int nxt) {
    int index = 0;
    for (int i = 0; i < n/2; i++) {
        s1 -= points[prev][t1[i]] + points[t1[i]][prev];
        s2 -= points[nxt][t2[i]] + points[t2[i]][nxt];
        if (t1[i] != prev) {
            s1 += points[nxt][t1[i]] + points[t1[i]][nxt];
        }
        if (t2[i] != nxt) {
            s2 += points[prev][t2[i]] + points[t2[i]][prev];
        } else {
            index = i;
        }
    }
    return index;
}

bool assignTeam(){
    int index = n/2 - 1, prev = t1[index], nxt, index2 = 0;
    while (prev >= index + n/2) {
        index--;
        prev = t1[index];
    }
    if (index == 0) {
        return false;
    }
    nxt = prev + 1;
    index2 = cal(prev, nxt);
    t1[index] = nxt;
    t2[index2] = prev;
    index++;
    while (index < n/2) {
        nxt += 1;
        prev = t1[index];
        if (prev != nxt) {
            index2 = cal(prev,nxt);
            t1[index] = nxt;
            t2[index2] = prev;
        }
        index++;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n;
    points.assign(n, vector<int>(n,0));
    t1.assign(n/2,0);
    t2.assign(n/2,0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> points[i][j];
        }
        if (i < n/2) {
            t1[i] = i;
        } else {
            t2[i - n/2] = i;
        }
    }
    for (int i = 0; i < n/2; i++) {
        for (int j = i + 1; j < n/2; j++) {
            s1 += points[t1[i]][t1[j]] + points[t1[j]][t1[i]];
            s2 += points[t2[i]][t2[j]] + points[t2[j]][t2[i]];
        }
    }
    int diff = min(1000000000, abs(s1 - s2));
    while (assignTeam()) {
        diff = min(diff, abs(s1 - s2));
    }
    cout << diff;
}