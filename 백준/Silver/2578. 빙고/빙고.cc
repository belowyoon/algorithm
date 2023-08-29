#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int bingo[5][5] = {0};
int line = 0;
bool diagonal[2];
unordered_map<int, pair<int, int>> findBingo;

int checkBingo(int x, int y) {
    bingo[x][y] = 0;
    int flag[4] = {0};
    for (int i = 0; i < 5; i++){
        if (bingo[x][i] == 0) {
            flag[0]++;
        }
        if (bingo[i][y] == 0) {
            flag[1]++;
        }
        if (!diagonal[0]) {
            if (bingo[i][i] == 0) {
                flag[2]++;
            } 
        }
        if (!diagonal[1]) {
            if (bingo[i][4-i] == 0) {
                flag[3]++;
            }
        }      
    }
    for (int i = 0; i < 4; i++) {
        if (flag[i] == 5) {
            if (i == 2) {
                diagonal[0] = true;
            }
            if (i == 3) {
                diagonal[1] = true;
            }
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