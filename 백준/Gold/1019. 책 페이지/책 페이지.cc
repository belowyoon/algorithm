#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> ans;
vector<int> num;
vector<int> dp;

void fillLast(int x) {
    int frt = 0, bck = 1;
    for (int i = num.size() - 1; i >= 0; i--) {
        if (x != i) {
            if (i > x) {
                frt = frt * 10 + num[i];
            }
            else {
                bck *= 10;
            }
        }
    }
    frt = frt - pow(10, num.size()-x-2) + 1;
    frt = max(frt, 1);
    for (int i = 0; i < num[x]; i++) { 
        if (x == num.size() - 1 && i == 0) continue;
        ans[i] += bck * frt;
    }
    if (x-1 >= 0) ans[num[x]] += dp[x-1];
    else ans[num[x]] += 1;
    frt = max(frt - 1, 0);
    for (int i = num[x]; i <= 9; i++) {
        ans[i] += bck * frt;
    }
    return;
}

void fillNum(int cnt) {
    int tmp;
    for (int i = 0; i < 10; i++) {
        if (i == 0) tmp = pow(10, cnt) * (cnt);
        else tmp = pow(10, cnt) * (cnt + 1);
        if (cnt != 0) tmp -= pow(10, cnt - 1) * cnt;
        ans[i] += tmp;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n, t, res, cnt = 0;
    cin >> n;
    res = n % 10;
    t = n / 10;
    ans.assign(10, 0);
    num.push_back(res);
    while(t) {
        fillNum(cnt);
        cnt++;
        res = t % 10;
        t /= 10;
        num.push_back(res);
    }
    dp.assign(num.size(), 0);
    dp[0] = num[0] + 1;
    for (int x = 1; x < num.size(); x++) {
        int sum = 0;
        for (int i = 0; i < num[x]; i++) {
            if (x == num.size()-1 && i == num[x]) continue;
            sum += pow(10, x);
        }
        sum += dp[x - 1];
        dp[x] = sum;
    }
    for (int i = num.size() - 1; i >= 0; i--) {
        fillLast(i);
    }
    for (int i = 0; i < 10; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}