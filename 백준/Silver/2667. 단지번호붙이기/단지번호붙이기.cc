#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int map[25][25];
int visited[25][25];
int n;
int cnt = 0;

void dfs(int l, int r) {
    if (l < 0 || l >= n || r < 0 || r >= n ) {
		return;
	} 
    if(visited[l][r] == 1) 
        return;
    if (map[l][r] == 1) {
        visited[l][r] = 1;
        cnt++;
        dfs(l-1,r);
        dfs(l, r-1);
        dfs(l+1,r);
        dfs(l,r+1);
    }
    
    return;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    

    cin >> n;

    vector<int> result;

    for (int i = 0; i < n; i++) {
        vector<int> line;
        for (int j = 0; j < n; j++) {
            char temp;
            cin >> temp;
            map[i][j] = temp - '0';
            visited[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                cnt = 0;
                dfs(i,j);
                result.push_back(cnt);
            }
        }
    }



    cout << result.size() << '\n';

    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }

    return 0;
}