#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (l.size() > r.size()) {
            if (x >= l.top()) {
                r.push(x);
            } else {
                r.push(l.top());
                l.pop();
                l.push(x);
            }
        } else if (l.size() < r.size()) {
            if (x <= r.top()) {
                l.push(x);
            } else {
                l.push(r.top());
                r.pop();
                r.push(x);
            }
        } else {
            if (r.empty()) {
                r.push(x);
            }
            else if (x > r.top()) {
                r.push(x);
            } else {
                l.push(x);
            }
        }
        if (l.size() < r.size()) cout << r.top() << '\n';
        else cout << l.top() << '\n';
    }
    return 0;
}
