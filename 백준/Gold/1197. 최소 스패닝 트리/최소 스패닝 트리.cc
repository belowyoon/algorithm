#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> parent;

int Find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = Find(parent[x]);
}

bool SameParent(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);
    if (pa != pb) 
        return false;
    return true;
}

void Union(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);
    parent[pa] = parent[pb];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    int v, e, a, b, c;
    cin >> v >> e;
    vector<pair<int, pair<int, int>>> arr;
    parent.assign(v+1, 0);
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        arr.push_back({c, {a,b}});
    }
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }
    int res = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < e; i++) {
        if (!SameParent(arr[i].second.first, arr[i].second.second)) {
            Union(arr[i].second.first, arr[i].second.second);
            res += arr[i].first;
        }
    }
    cout << res;
    return 0;
}