#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> sorted;

int binarySearch(int x) {
    int l = 0, r = sorted.size()-1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (sorted[mid] < x) {
            mid++;
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return mid;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> lines(n, {0,0});

    for (int i = 0; i < n; i++) {
        cin >> lines[i].first >> lines[i].second;
    }
    sort(lines.begin(), lines.end());

    int cnt = 1;
    sorted.push_back(lines[0].second);
    for (int i = 1; i < n; i++) {
        if (lines[i].second > sorted[sorted.size()-1]) {
            sorted.push_back(lines[i].second);
            cnt++;
        } else {
            int idx =  binarySearch(lines[i].second);
            sorted[idx] = lines[i].second;
        }
    }
    cout << n - cnt;

    return 0;
}