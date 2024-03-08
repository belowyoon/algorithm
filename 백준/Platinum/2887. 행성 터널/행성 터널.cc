#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, result = 0;
vector<pair<int,int>> v[3];
vector<pair<int, pair<int, int>>> planet;
int parent[100001];

int Find(int x) {
    if (parent[x] == x)
        return x;
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

    cin >> n;
    int x, y, z;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        v[0].push_back({x,i});
        v[1].push_back({y,i});
        v[2].push_back({z,i});
        parent[i] = i;
    }
    sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	sort(v[2].begin(), v[2].end());

    for (int i = 0; i < n - 1; i++){
        planet.push_back({abs(v[0][i].first - v[0][i + 1].first), {v[0][i].second, v[0][i + 1].second}});
        planet.push_back({abs(v[1][i].first - v[1][i + 1].first), {v[1][i].second, v[1][i + 1].second}});
        planet.push_back({abs(v[2][i].first - v[2][i + 1].first), {v[2][i].second, v[2][i + 1].second}});
    }

    sort(planet.begin(), planet.end());

    for (int i = 0; i < planet.size(); i++){
		if (!SameParent(planet[i].second.first, planet[i].second.second)){
			result += planet[i].first;
			Union(planet[i].second.first, planet[i].second.second);
		}

	}
    cout << result;
    return 0;
}