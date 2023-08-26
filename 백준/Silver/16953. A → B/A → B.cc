#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int a,b;
    cin >> a >> b;
    queue<int> q;

    int depth = 0;
    q.push(a);
    while (!q.empty()) {
        int size = q.size();
        depth++;
        for (int i = 0; i < size; i++) {
            int num = q.front();
            q.pop();
            if (num > 1000000000) {
                continue;
            }
            if (num == b) {
                cout << depth;
                return 0;
            }
            q.push(num * 2);
            if (num < 100000000) {
                q.push(num * 10 + 1);
            }
        }
    }
    cout << -1;

    return 0;
}