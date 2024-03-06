#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    vector<int> index(n, 0);
    vector<int> arr(n, 0);
    vector<int> sorts;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sorts.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        if (sorts[sorts.size()-1] < arr[i]) {
            sorts.push_back(arr[i]);
            index[i] = sorts.size() - 1;
        } else {
            int l = 0;
            int r = sorts.size() - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (arr[i] <= sorts[mid]) r = mid;
                else l = mid + 1;
            }
            sorts[l] = arr[i];
            index[i] = l;
        }
    }
    cout << sorts.size() << '\n';
    vector<int> ans;
    int fIndex = sorts.size() - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (fIndex == index[i]) {
            ans.push_back(arr[i]);
            fIndex--;
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    return 0;
}