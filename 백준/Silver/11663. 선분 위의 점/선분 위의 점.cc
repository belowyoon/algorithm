#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int arr[100000] = {-1};

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    for (int i = 0; i < m; i++)
    {
        int first, last;
        cin >> first >> last;
        int l = 0, r = n - 1;
        int mid, fIndex, lIndex;
        while (l <= r)
        {
            mid = (r - l) / 2 + l;
            fIndex = mid;
            if (arr[mid] == first)
            {
                break;
            }
            else if (arr[mid] < first)
            {
                l = mid + 1;
                fIndex = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        l = 0;
        r = n - 1;
        while (l <= r)
        {
            mid = (r - l) / 2 + l;
            lIndex = mid;
            if (arr[mid] == last)
            {
                break;
            }
            else if (arr[mid] < last)
            {
                l = mid + 1;
            }
            else
            {
                lIndex = mid - 1;
                r = mid - 1;
            }
        }
        cout << lIndex - fIndex + 1 << "\n";
    }
    return 0;
}