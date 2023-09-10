#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    vector<int> score;
    score.assign(n,0);
    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }
    int result = 0;
    for (int i = n-1; i > 0; i--) {
        while (score[i] <= score[i-1]) {
            score[i-1]--;
            result++;
        }
    }
    cout << result;
}