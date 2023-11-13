#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<char>> board;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int x, y, rx, ry, bx, by, result = 100;

void move(int mx, int my, int cnt){
    if (cnt > 10) {
        return;
    }
    int moveR = 0, moveB = 0;
    bool rFlag = true, bFlag = true, rHole = false, bHole = false;
    if (mx != 0 || my != 0) {
        while (rFlag || bFlag){
            if (board[rx + mx][ry + my] == '.') {
                rFlag = true;
                board[rx][ry] = '.';
                board[rx + mx][ry + my] = 'R';
                moveR++;
                rx += mx;
                ry += my;
            } else {
                rFlag = false;
            }
            if (board[bx + mx][by + my] == '.') {
                bFlag = true;
                board[bx][by] = '.'; 
                board[bx + mx][by + my] = 'B'; 
                moveB++;
                bx += mx;
                by += my;
            } else {
                bFlag = false;
            }
            if (rx == x && ry == y) {
                board[rx][ry] = '.';
                rHole = true;
            }
            if (bx == x && by == y) {
                board[bx][by] = '.';
                bHole = true;
            }
        }
        if (rHole && !bHole) {
            result = min(result, cnt);
        }
        if (rHole || bHole) {
            return;
        }
    }
    int orx = rx, ory = ry, obx = bx, oby = by;
    for (int i = 0; i < 4; i++) { 
        move(dx[i], dy[i], cnt + 1);
        board[rx][ry] = '.';
        board[bx][by] = '.';
        board[orx][ory] = 'R';
        board[obx][oby] = 'B'; 
        rx = orx; ry = ory; bx = obx; by = oby;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n >> m;
    board.assign(n, vector<char>(m,' '));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'O'){
                x = i; y = j;
                board[x][y] = '.';
            } else if (board[i][j] == 'R'){
                rx = i; ry = j;
            } else if (board[i][j] == 'B'){
                bx = i; by = j;
            }
        }
    }
    move(0,0,0);
    if (result > 10) {
        result = -1;
    }
    cout << result;
    return 0;
}