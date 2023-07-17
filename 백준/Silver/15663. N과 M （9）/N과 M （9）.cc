#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
vector<int> selected;
vector<int> nums;
vector<bool> visited;
unordered_set<string> res;
int n, m;

void permutation(int depth) {
    if (depth == m) {
        string temp = "";
        for (int i = 0; i < m; i++) {
            temp += to_string(selected[i]) + " ";
        }
        if (res.find(temp) == res.end()) {
            res.insert(temp);
            cout << temp << '\n';
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            selected[depth] = nums[i];
            permutation(depth+1);
            visited[i] = false;
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
