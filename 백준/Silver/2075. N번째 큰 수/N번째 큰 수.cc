#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            pq.push(temp);
        }
        if (pq.size() > n) {
            priority_queue<int> temp;
            for (int i = 0; i < n; i++) {
                temp.push(pq.top());
                pq.pop();
            }
            pq = temp;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(i == n-1){
            cout << pq.top();
        }
        pq.pop();
    }
    return 0;
}