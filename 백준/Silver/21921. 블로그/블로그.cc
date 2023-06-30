#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    int arr[250002];

    arr[0] = 0;
    for (int i = 1; i < n + 1; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    int maxVisitor = -1, time = 0;

    for (int i = 0; i < n - x + 1; i++)
    {
        if (arr[i+x]-arr[i] > maxVisitor) {
            maxVisitor = arr[i+x]-arr[i];
            time = 1;
        }
        else if (arr[i+x]-arr[i] == maxVisitor) {
            time++;
        }
    }

    if (maxVisitor == 0) {
        cout << "SAD";
    } else {
        cout << maxVisitor << '\n' << time;
    }
    return 0;
}