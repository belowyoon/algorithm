#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> parent;
int Find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = Find(parent[x]);
}
bool SameParent(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b)
        return false;
    else
        return true;
}
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a != b)
		parent[a] = b;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> road;
    parent.assign(n+1, 0);
    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        road.push_back({c, {a, b}});
    }
    sort(road.begin(), road.end());
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    int res = 0, prev = 0;
    for (int i = 0; i < road.size(); i++) {
        if (!SameParent(road[i].second.first, road[i].second.second)) {
            res += road[i].first;
            prev = road[i].first;
            Union(road[i].second.first, road[i].second.second);
        }
    }
    cout << res - prev;
    return 0;
}