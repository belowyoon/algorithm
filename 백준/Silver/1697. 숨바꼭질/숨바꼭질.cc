#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n, k;
    bool visited[100001] = {false};
    int result[100001] = {0};
    queue<int> q;
    cin >> n >> k;
    q.push(n);

    int depth = -1;
    while(!q.empty()) {
        int size = q.size();
        depth++;
        for(int i = 0; i < size; i++) {
            int x = q.front();
            q.pop();
            if (x < 0 || x >= 100001) {
                continue;
            }
            if (visited[x]) {
                continue;
            }
            visited[x] = true;
            result[x] = depth;
            if(x == k) {
                cout << result[x];
                return 0;
            }
            q.push(2*x);
            q.push(x-1);
            q.push(x+1);
        }
    }

    return 0;
}