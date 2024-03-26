#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> parent;
int p, g;

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> g >> p;
    vector<int> arr(p, 0);
    for (int i = 0; i < p; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i <= g; i++) {
        parent.push_back(i);
    }
   
    int cnt = 0;
    for (int i = 0; i < p; i++) {
        int gate = Find(arr[i]);
        if (gate == 0) break;
        Union(gate, gate-1);
        cnt++;
    }
    cout << cnt;
    return 0;
}