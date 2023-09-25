#include <iostream>
#include <algorithm>
using namespace std;

int n, l;
int map[100][100];
bool slope[100];

bool checkHorizontal(int k){
    int height = map[k][0];
    fill(slope, slope+n, false);
    for (int i = 1; i < n; i++) {
        if (height == map[k][i]) {
            continue;
        }
        if (height - map[k][i] >= 2) {
            return false;
        }
        if (map[k][i] > height) {
            if (i - l >= 0) {
                for(int j = i - 1; j >= i - l; j--) {
                    if (slope[j] || map[k][j] != map[k][i] - 1) {
                        return false;
                    } else {
                        slope[j] = true;
                    }
                }
                height++;
            } else {
                return false;
            }
        } else {
            if (i + l <= n) {
                for(int j = i; j < i + l; j++) {
                    if (slope[j] || map[k][j] != height - 1) {
                        return false;
                    } else {
                        slope[j] = true;
                    }
                }
                height--;
            } else {
                return false;
            }
        }

    }
    return true;
}

bool checkVertical(int k){
    int height = map[0][k];
    fill(slope, slope+n, false);
    for (int i = 1; i < n; i++) {
        if (height == map[i][k]) {
            continue;
        }
        if (height - map[i][k] >= 2) {
            return false;
        }
        if (map[i][k] > height) {
            if (i - l >= 0) {
                for(int j = i - 1; j >= i - l; j--) {
                    if (slope[j] || map[j][k] != map[i][k] - 1) {
                        return false;
                    } else {
                        slope[j] = true;
                    }
                }
                height++;
            } else {
                return false;
            }
        } else {
            if (i + l <= n) {
                for(int j = i; j < i + l; j++) {
                    if (slope[j] || map[j][k] != height - 1) {
                        return false;
                    } else {
                        slope[j] = true;
                    }
                }
                height--;
            } else {
                return false;
            }
        }

    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (checkHorizontal(i)){
            result++;
        }
        if (checkVertical(i)) {
            result++;
        }
    }
    cout << result;
    return 0;
}