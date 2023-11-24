#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool check(vector<string> place, int a, int b) {
    
    queue<pair<int,int>> q;
    q.push({a,b});
    int depth = 0;
    while(!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            //cout << depth << " : " << x << " " << y << "\n";
            q.pop();
            if (place[x][y] == 'P' && depth != 0) {
                //cout << depth << " : " << x << " " << y << "\n";
                return 0;
            }
            if (depth < 2) {
                for (int j = 0; j < 4; j++) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) {
                        continue;
                    }
                    if (place[nx][ny] != 'X' && !(nx == a && ny == b)) {
                        q.push({nx, ny});
                    }
                }
            } 
        }
        depth++;
    }
    return 1;
}


int checkRoom(vector<string> place) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++){
            if (place[i][j] == 'P') {
                if (check(place, i, j) == 0) return 0;
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0; i < places.size(); i++) {
        cout << i << '\n';
        answer.push_back(checkRoom(places[i]));
    }
    return answer;
}