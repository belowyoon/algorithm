#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    int n,m;
    vector<int> cards;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cards.push_back(t);
    }

    sort(cards.begin(), cards.end());
    
    int result = 0, calc = 10000000, sum = 0;
    for (int i = 0; i < cards.size(); i++) {
        for (int j = i + 1; j < cards.size(); j++) {
            for (int k = j + 1; k < cards.size(); k++) {
                sum = cards[i] + cards[j] + cards[k];
                if (abs(sum - m) < calc && sum <= m) {
                    calc = abs(sum - m);
                    result = sum;
                }
            }
        }
    }
    cout << result;
    return 0;
}