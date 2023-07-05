#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> card;
int n;

int binarySearch(int find) {
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l+r) / 2;
        if (card[mid] == find) {
            return 1;
        } else if (card[mid] < find) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }

    }
    return 0;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        card.push_back(temp);
    }
    sort(card.begin(), card.end());
		
    int m, k;
    cin >> m;
		
    for (int i = 0; i < m; i++){
        cin >> k;
        cout << binarySearch(k) << ' ';
    }
    return 0;
}