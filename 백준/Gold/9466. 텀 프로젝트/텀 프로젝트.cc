#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> students;
vector<bool> visited;
int n;

int findLoop(int idx, queue<int> q) {
    while (!q.empty()){
        int s = q.front();
        //cout << s << " " << students[idx] << '\n';
        visited[idx] = true;
        if (!visited[students[idx]]) {
            q.push(students[idx]);
            idx = students[idx];
        } else {
            if (idx == students[idx]) {
                return 1;
            }
            if (s == students[idx]) {
                return q.size();
            }
            //cout << s << '\n';
            q.pop();
        }
    }
    return 0;
}

void loop() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        queue<int> q;
        if (!visited[i] && !visited[students[i]]) {
            visited[i] = true;
            if (i == students[i]){
                cnt += 1;
            }
            else {
                q.push(i);
                q.push(students[i]);
                cnt += findLoop(students[i] ,q);
            }
        }
    }
    cout << n - cnt << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t > 0) {
        cin >> n;
        students.assign(n+1, 0);
        visited.assign(n+1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> students[i];
        }
        int res = 0;
        loop();
        t--;
    }
    return 0;
}
