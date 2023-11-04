#include <iostream>
#include <algorithm>
using namespace std;

int r, c, t;
vector<vector<int>> room;
pair<int, int> air[2];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int direction[2][2][4] =  {
    {
        {0, -1, 0, 1},
        {1, 0, -1, 0}
    },
    {   {0, 1, 0, -1},
        {1, 0, -1, 0}
    }
};

void dust() {
    vector<vector<int>> newRoom;
    newRoom.assign(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int cnt = 0;
            if (room[i][j] < 5) {
                newRoom[i][j] += room[i][j];
                continue;
            }
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                    continue;
                }
                if (room[nx][ny] != -1) {
                    newRoom[nx][ny] += room[i][j] / 5;
                    cnt++;
                }
            }
            newRoom[i][j] += room[i][j] - cnt * (room[i][j] / 5);
        }
    }
    copy(newRoom.begin(), newRoom.end(), room.begin());
}

void wind() {
    for (int i = 0; i <= 1; i++) {
        int prev = 0;
        int dir = 0;
        int dx = direction[i][0][dir];
        int dy = direction[i][1][dir];
        int nx = air[i].first + dx;
        int ny = air[i].second + dy;
        int temp;
        while (true) {
            if (nx < 0 || nx >= r  || ny < 0 || ny >= c ) {
                nx -= dx;
                ny -= dy;
                dir += 1;
                dx = direction[i][0][dir];
                dy = direction[i][1][dir];
                nx += dx;
                ny += dy;
            }
            if (room[nx][ny] == -1) {
                break;
            }
            temp = room[nx][ny];
            room[nx][ny] = prev;
            prev = temp;
            nx += dx;
            ny += dy;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> r >> c >> t;
    room.assign(r, vector<int>(c, 0));
    int index = 0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> room[i][j];
            if (room[i][j] == -1) {
                air[index] = {i,j};
                index++;
            }
        }
    }
    
    for (int i = 0; i < t; i++) {
        dust();
        wind();
    }
    
    int result = 0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (room[i][j] > 0) {
                result += room[i][j];
            }
        }
    }

    cout << result;
    return 0;
}