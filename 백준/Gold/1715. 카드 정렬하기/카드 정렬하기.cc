#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);

    int n;
    priority_queue < int, vector<int>, greater<int> > pq;
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        pq.push(temp);
    }
    int first, second;
    if (pq.size() == 1) {
        cout << 0;
        return 0;
    }
    int result = 0;
    while(!pq.empty()) {
        first = pq.top();
        pq.pop();
        if (pq.empty()) {
            break;
        }
        second = pq.top();
        pq.pop();
        result += first + second;
        pq.push(first+second);
    }
    cout << result;
    return 0;
}