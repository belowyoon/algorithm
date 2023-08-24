#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int bingo[5][5] = {0};
int line = 0;
unordered_map<int, pair<int, int>> findBingo;

int checkBingo(int x, int y) {
    bingo[x][y] = 0;
    int flag[4] = {0};
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++) {
            if (i == x) {
                if (bingo[i][j] == 0) {
                    flag[0]++;
                }
            } else {
                int num = (y-j) / (x-i);
                int remainder = (y-j) % (x-i);
                if (num == 1 && remainder == 0) {
                    if (bingo[i][j] == 0) {
                        flag[2]++;
                    }
                }
                if (num == -1 && remainder == 0) {
                    if(bingo[i][j] == 0) {
                        flag[3]++;
                    }
                }
            }
            if (j == y && bingo[i][j] == 0) {
                flag[1]++;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (i < 2 && flag[i] == 5) {
            line++;
        } 
        if (i >= 2 && flag[i] == 4) {
            line++;
        } 
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++) {
            cin >> bingo[i][j];
            findBingo[bingo[i][j]] = {i,j};
        }
    }

    int t;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++) {
            cin >> t;
            checkBingo(findBingo[t].first, findBingo[t].second);
            if (line >= 3) {
                cout << i * 5 + (j + 1);
                return 0;
            }
        }
    }
    return 0;
}