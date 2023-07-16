#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
vector<int> selected;
int n, m;

void permutation(int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << selected[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        selected[depth] = nums[i];
        permutation(depth+1);
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        nums.push_back(i+1);
    }
    selected.assign(m,0);
    permutation(0);
    return 0;
}
