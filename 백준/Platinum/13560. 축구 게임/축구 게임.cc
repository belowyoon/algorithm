#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> score;
    bool flag = true;
    cin >> n;

    int sum = 0;
    score.assign(n + 1,0);
    for (int i = 1; i <= n; i++) {
        cin >> score[i];
        sum += score[i];
    }
    if (sum != (n * (n-1)) / 2) {
        cout << -1;
        return 0;
    }

    sort(score.begin() + 1, score.end());
    for (int i = 1; i <= n; i++) {
        if (score[i] > n - 1 || score[i] < 0) {
            flag = false;
            break;
        }
        for (int j = 0; j < n - score[i] - i; j++) {
            score[n - j]--;
        }
        sort(score.begin()+i+1, score.end());
    }
    if (flag) cout << 1;
    else cout << -1;

    return 0;
}

