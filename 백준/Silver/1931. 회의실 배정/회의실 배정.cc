#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

bool compare ( pair <int, int> a,  pair <int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);

    int n;
    vector< pair <int, int> > time;
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        time.push_back(make_pair(start,end));
    }

    sort(time.begin(), time.end(), compare);

    int end = -1;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (time[i].first >= end) {
            count++;
            end = time[i].second;
        }
    }

    cout << count;

    return 0;
}
