#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
vector<int> selected;
int n, m;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    cin >> n >> m;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        nums.push_back(t);
    }
    sort(nums.begin(), nums.end());
    selected.assign(n,0);
    for (int i = 0; i < m; i++) {
        selected[i] = 1;
    }
    do {
        for (int i = 0; i < nums.size(); ++i) {
            if (selected[i] == 1)
                cout << nums[i] << ' ';
        }
        cout << '\n';
    } while (prev_permutation(selected.begin(), selected.end()));
    return 0;
}
