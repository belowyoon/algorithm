#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
int n;
int result = 0;
vector<int> strong;
vector<int> weight;

void breakEgg(int index) {
    if (index == n) {
        int cnt = 0;
        for (int i = 0; i < strong.size(); i++) {
            if (strong[i] <= 0) {
                cnt++;
            }
        }
        result = max(result, cnt);
        return;
    }
    if (strong[index] <= 0) {
        breakEgg(index+1);
        return;
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (i != index && strong[i] > 0) {
            strong[i] -= weight[index];
            strong[index] -= weight[i];
            breakEgg(index+1);
            strong[i] += weight[index];
            strong[index] += weight[i];
        } else {
            flag++;
        }
    }
    if (flag == n) {
        breakEgg(index+1);
        return;
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    cin >> n;

    int s, w;
    for (int i = 0; i < n; i++) {
        cin >> s >> w;
        strong.push_back(s);
        weight.push_back(w);
    }
    breakEgg(0);
    cout << result;
    return 0;
}
