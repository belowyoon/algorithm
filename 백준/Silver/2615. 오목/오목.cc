#include <iostream>
#include <algorithm>
using namespace std;

int omok[19][19];

bool check(int x, int y, int k) {
    if (x < 0 || x >= 19 || y < 0 || y >= 19) {
        return false;
    }
    if (omok[x][y] == k) {
        return true;
    }
    return false;
}

bool checkLine(int x, int y, int k) {
    int flag[4] = {0};
    for (int i = 1; i < 5; i++) {
        if (check(x, y+i, k)) {
            flag[0]++;
        }
        if (check(x+i, y, k)) {
            flag[1]++;
        }
        if (check(x+i, y+i, k)) {
            flag[2]++;
        }
        if (check(x-i, y+i, k)) {
            flag[3]++;
        }
    }
    if (check(x, y-1, k) || check(x, y+5, k)) {
        flag[0] = 0;
    }
    if (check(x-1, y, k) || check(x+5, y, k)) {
        flag[1] = 0;
    }
    if (check(x-1, y-1, k) || check(x+5, y+5, k)) {
        flag[2] = 0;
    }
    if (check(x+1, y-1, k) || check(x-5, y+5, k)) {
        flag[3] = 0;
    }
    for (int i = 0; i < 4; i++) {
        if (flag[i] == 4) {
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> omok[i][j];
        }
    }

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (omok[i][j] == 1) {
                if (checkLine(i, j, 1)) {
                    cout << 1 << '\n' << i+1 << " " << j+1;
                    return 0;
                }
            } 
            else if (omok[i][j] == 2) {
                if (checkLine(i, j, 2)) {
                    cout << 2 << '\n' << i+1 << " " << j+1;
                    return 0;
                }
            }
        }
    }
    cout << 0;

    return 0;
}