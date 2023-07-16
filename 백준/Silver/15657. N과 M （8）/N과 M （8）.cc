#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> selected;
vector<int> nums;
int n, m;

void combination(int depth, int nxt) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << selected[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = nxt; i < n; i++) {
        selected[depth] = nums[i];
        combination(depth+1, i);
    }
}
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
    selected.assign(m,0);
    combination(0,0);
    return 0;
}
