#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n;
    int minSum[3] = {0,0,0};
    int maxSum[3] = {0,0,0};
    cin >> n;
    int t1, t2, t3, m1, m2;
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2 >> t3;
        m1 = min(minSum[0], minSum[1]);
        m2 = min(minSum[1], minSum[2]);
        minSum[0] = t1 + m1;
        minSum[1] = t2 + min(m1, m2);
        minSum[2] = t3 + m2;
        m1 = max(maxSum[0], maxSum[1]);
        m2 = max(maxSum[1], maxSum[2]);
        maxSum[0] = t1 + m1;
        maxSum[1] = t2 + max(m1, m2);
        maxSum[2] = t3 + m2;
    }
    cout << *(max_element(maxSum, maxSum + 3)) << " " << *(min_element(minSum, minSum + 3));
    return 0;
}