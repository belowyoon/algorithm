#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
vector<bool> light;

void menSwitch(int k) {
    int num = k;
    while (num <= n) {
        light[num] = !light[num];
        num = num + k;
    }
    return;
}
void womenSwitch(int k) {
    int i = 1;
    light[k] = !light[k];
    while (true) {
        if (k - i < 1 || k + i > n) {
            break;
        }
        if (light[k-i] != light[k+i]) {
            break;
        }
        light[k-i] = !light[k-i];
        light[k+i] = !light[k+i];
        i++;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n;
    light.assign(n + 1,false);
    
    int t;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        light[i] = t;
    }
    
    cin >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (x == 1) {
            menSwitch(y);
        }
        if (x == 2) {
            womenSwitch(y);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << light[i] << " ";
        if (i % 20 == 0) {
            cout << "\n";
        }
    }

    return 0;
}