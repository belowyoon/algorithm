#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n, t1, t2;
    vector<int> calendar;
    calendar.assign(366,0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2;
        for (int j = t1; j <= t2; j++) {
            calendar[j]++;
        }
    }
    int consecutive = 0, maxSchedule = 0, result = 0;
    for(int i = 1; i < 366; i++) {
        if (calendar[i] != 0) {
            consecutive++;
            maxSchedule = max(maxSchedule, calendar[i]);
        } else {
            result += consecutive * maxSchedule;
            consecutive = 0;
            maxSchedule = 0;
        }
    }
    result += consecutive * maxSchedule;
    cout << result;
  
    return 0;
}