#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
int n;
int result = 0;
int visited[15] = {0};
vector<int> queens;

bool check(int index, int j) {
    for (int i = 0; i < index; i++) {
        if (abs(queens[i] - j) == abs(i - index))
            return false;
    }
    return true;
}

void placeQueen(int index) {
    if(index == n) {
        result++;
        return;
    }
    for (int j = 0; j < n; j++) {
        if (visited[j] == 0) {
            visited[j] = 1;
            queens[index] = j;
            if (check(index, j)) {
                placeQueen(index+1);
            }
            visited[j] = 0;
        }
    }    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    cin >> n;
    queens.assign(n,-1);
    placeQueen(0);
    cout << result;
    return 0;
}