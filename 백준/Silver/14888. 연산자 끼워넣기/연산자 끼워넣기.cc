#include <iostream>
#include <algorithm>
using namespace std;

int n;
int num[11];
int maxNum = -1000000001;
int minNum = 1000000001;

void cal(int k, int oper[], int result) {
    if (k == 0) {
        maxNum = max(maxNum, result);
        minNum = min(minNum, result);
        return;
    }
    for (int j = 0; j < 4; j++) {
        if (oper[j] > 0) {
            oper[j]--;
            switch(j) {
                case 0:
                    cal(k - 1, oper, result + num[n - k]);
                    break;
                case 1:
                    cal(k - 1, oper, result - num[n - k]);
                    break;
                case 2:
                    cal(k - 1, oper, result * num[n - k]);
                    break;
                case 3:
                    cal(k - 1, oper, result / num[n - k]);
                    break; 
            } 
            oper[j]++;
        }    
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n;
    int oper[4] = {0};

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }

    cal(n-1, oper, num[0]);
    cout << maxNum << '\n' << minNum;

    return 0;
}