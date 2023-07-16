#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<bool> visited;
vector<int> selected;
vector<int> nums;
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
        if (visited[i] == 0) {
            visited[i] = 1;
            selected[depth] = nums[i];
            permutation(depth+1);
            visited[i] = 0;
        }
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
        visited.push_back(false);
    }
    sort(nums.begin(), nums.end());
    selected.assign(m,0);

    permutation(0);
    return 0;
}
