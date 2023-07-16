#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> selected;
int n, m;

void combination(int depth, int nxt) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << selected[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = nxt; i <= n; i++) {
        selected[depth] = i;
        combination(depth+1, i+1);
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    cin >> n >> m;
    selected.assign(m,0);
    combination(0,1);
    return 0;
}
