#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);

    int n, m;
    int crane[50] = {0};
    int box[10000] = {0};
    queue<int> q;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> crane[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> box[i];

    }
    sort(crane, crane + n, greater<int>());
    sort(box, box+m, greater<int>());

    for(int i = 0; i < m; i++) {
        q.push(box[i]);
    }

    int count = 0;
    while (!q.empty())
    {
        int index = 0;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int now = q.front();
            q.pop();
            //cout << i << " " << now << "\n";
            if (index < n) {
                if(now <= crane[index]) {
                    //cout << crane[index] << " " << now << '\n';
                    index++;
                } else {
                    q.push(now);
                }
            } else {
                q.push(now);
            }
        }
        if (size == q.size()) {
            cout << -1;
            return 0;
        }
        count++;
    }

    cout << count;

    return 0;
}