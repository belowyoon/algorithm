#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int score[34];
int map[34];
int turn[16];
bool point[34];
int dice[10];
int horse[4];
int result = 0;

void dfs(int idx, int sum) {
    if (idx == 10) {
        result = max(sum, result);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int cur = horse[i], prev = horse[i];
        int move = dice[idx];
        if (horse[i] == 5 || horse[i] == 10 || horse[i] == 15) {
            cur = turn[horse[i]];
            move--;
        }
        while (move--) {
            cur = map[cur];
        }
        if (point[cur] && cur != 21) continue;
        point[prev] = 0;
        point[cur] = 1;
        horse[i] = cur;
        dfs(idx + 1, sum + score[cur]);
        horse[i] = prev;
        point[prev] = 1;
        point[cur] = 0;
    }
    return;
}

void init() {
    for (int i = 0; i < 21; i++) map[i] = i+1;
    map[21] = 21;
    for (int i = 22; i < 27; i++) map[i] = i+1;
    map[27] = 20;
    map[28] = 29; map[29] = 30; map[30] = 25;
    map[31] = 32; map[32] = 25;

    turn[5] = 22; turn[10] = 31; turn[15] = 28;

    for (int i = 0; i < 21; i++) score[i] = 2 * i;
    score[22] = 13; score[23] = 16; score[24] = 19;
    score[25] = 25; score[26] = 30; score[27] = 35;
    score[28] = 28; score[29] = 27; score[30] = 26;
    score[31] = 22; score[32] = 24;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    for (int i = 0; i < 10; i++) {
        cin >> dice[i];
    }
    init();
    dfs(0, 0);
    cout << result;
    return 0;
}