#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <queue>

using namespace std;
int n,l,r;
int ppl[50][50] = {0};
int visited[50][50] = {0};
int sum = 0;
queue<pair<int,int>> save;

void dfs(int i, int j, int compare) {
    if (i < 0 || i >= n || j < 0 || j >= n)
        return;
    if (visited[i][j] == 1)
        return;
    if ((abs(ppl[i][j] - compare) >= l && abs(ppl[i][j] - compare) <= r) || compare == -1) {
        sum+=ppl[i][j];
        save.push(make_pair(i,j));
        compare = ppl[i][j];
        visited[i][j] = 1;
        dfs(i-1, j, compare);
        dfs(i, j-1, compare);
        dfs(i+1, j, compare);
        dfs(i, j+1, compare);
    } 
    return;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            int t;
            cin >> t;
            ppl[i][j] = t;
        }
    }

    int cnt = -1;
    bool flag = true;
    while (flag) {
        flag = false;
        cnt++;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                sum = 0;
                dfs(i,j,-1);
                if (save.size() >= 2) {
                    int aver = sum / save.size();
                    flag = true;
                    while (!save.empty())
                    {
                        pair<int,int> temp = save.front();
                        save.pop();
                        //cout << temp.first << " " << temp.second << " " << aver << '\n';
                        ppl[temp.first][temp.second] = aver;
                    }
                } else {
                    while (!save.empty()){
                        save.pop();
                    }
                }

            }
        }
        for (int i = 0; i < n; i++) {
            fill_n(visited[i], n , 0);
        }

    }
    cout << cnt ;
    return 0;
}