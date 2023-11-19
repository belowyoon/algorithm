#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
vector<vector<pair<int,int>>> tree;

pair<int,int> bfs(int i) {
	queue<int> q;
	vector<int> dist;
	int maxDist = 0;
	int endNode = 0;
	dist.assign(n+1, -1);
	q.push(i);
	dist[i] = 0;
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		for (int j = 0; j < tree[node].size(); j++) {
			int nxt = tree[node][j].first;
			int nxtDist = dist[node] + tree[node][j].second;
			if (dist[nxt] == -1) {
				dist[nxt] = nxtDist;
				q.push(nxt);
				if (nxtDist > maxDist) {
					maxDist = nxtDist;
					endNode = nxt;
				}
			} 
		}
	}
	return {endNode, maxDist};
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

	cin >> n;
	tree.assign(n+1, vector<pair<int,int>>());
	int n1, n2, d;
	for (int i = 1; i <= n; i++) {
		cin >> n1;
		while(true) {
			cin >> n2;
			if (n2 == -1) {
				break;
			}
			cin >> d;
			tree[n1].push_back({n2,d});
		}
	}
	int endNode = bfs(1).first;
	int res = bfs(endNode).second;
	cout << res;
    return 0;
}
