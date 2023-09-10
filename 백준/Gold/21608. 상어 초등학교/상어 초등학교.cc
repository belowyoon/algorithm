#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <cmath>
using namespace std;

int n;
vector<vector<int>> seats;
vector<unordered_set<int>> friends;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int findBest(int x, int y, int s) {
    int nx, ny, score = 0;

    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
            continue;
        }
        if (seats[nx][ny] == 0) {
            score += 1;
        }
        else {
            if (friends[s-1].find(seats[nx][ny]) != friends[s-1].end()) {
                score += 5;
            }
        }
    }
    return score;
}

void getSeat(int s) {
    int x,y;
    int bestScore = -1, score = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (seats[i][j] == 0) {
                score = findBest(i,j,s);
                if (score > bestScore) {
                    x = i; 
                    y = j;
                    bestScore = score;
                }
            }
        }
    }
    seats[x][y] = s;
    return;
}

int getSatisfyScore(int x, int y) {
    int nx, ny, num = 0, s = seats[x][y];
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
            continue;
        }
        if (friends[s-1].find(seats[nx][ny]) != friends[s-1].end()) {
            num++;
        }
    }
    return pow(10, num - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n;
    seats.assign(n,vector<int>(n,0));
    friends.assign(n * n, unordered_set<int>());
    
    int s;
    int f[4];
    for(int i = 0; i < n * n; i++) {
        cin >> s >> f[0] >> f[1] >> f[2] >> f[3];
        for (int i = 0; i < 4; i++) {
            friends[s-1].insert(f[i]);
        }
        getSeat(s);
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result += getSatisfyScore(i,j);
        }
    }
    cout << result;
    return 0;
}