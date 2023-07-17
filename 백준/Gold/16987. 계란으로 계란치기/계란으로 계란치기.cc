#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
int n;
vector<int> result;

void breakEgg(vector<int> strong, vector<int> weight, int index) {
    if (index == n) {
        int cnt = 0;
        for (int i = 0; i < strong.size(); i++) {
            //cout << strong[i] << " ";
            if (strong[i] <= 0) {
                cnt++;
            }
        }
        //cout << "cnt : " << cnt << "\n";
        result.push_back(cnt);
        return;
    }
    if (strong[index] <= 0) {
        //cout << index << " : " << strong[index] << "\n";
        breakEgg(strong, weight, index+1);
        return;
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (i != index && strong[i] > 0) {
            strong[i] -= weight[index];
            strong[index] -= weight[i];
            breakEgg(strong, weight, index+1);
            strong[i] += weight[index];
            strong[index] += weight[i];
        } else {
            flag++;
        }
    }
    if (flag == n) {
        //cout << index << " : " << strong[index] << "\n";
        breakEgg(strong, weight, index+1);
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
    vector<int> weight;
    vector<int> strong;
    for (int i = 0; i < n; i++) {
        cin >> s >> w;
        strong.push_back(s);
        weight.push_back(w);
    }
    breakEgg(strong, weight, 0);
    int m = *max_element(result.begin(), result.end());
    cout << m;
    return 0;
}
