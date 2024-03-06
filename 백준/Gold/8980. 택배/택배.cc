#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Box {
    int s;
    int e;
    int n;
};

bool compare(Box& a, Box& b){
    if (a.e == b.e) {
        return a.s > b.s; 
    }
    return a.e > b.e;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    
    int n, c, t, t1, t2, t3;
    cin >> n >> c;
    cin >> t;
    vector<Box> arr(t, {0,0,0});
    vector<int> capacity(n+1, 0);

    for (int i = 0; i < t; i++) {
        cin >> arr[i].s >> arr[i].e >> arr[i].n;
    }
    sort(arr.begin(), arr.end(), compare);

    int result = 0;
    for (int i = 0; i < t; i++) {
        int maxNum = 0;
        for (int j = arr[i].s; j < arr[i].e; j++) {
            maxNum = max(maxNum, capacity[j]);
        }
        int now = min(arr[i].n, c - maxNum);
        result += now;
        for (int j = arr[i].s; j < arr[i].e; j++) {
            capacity[j] += now;
        }
    }
    cout << result;
    return 0;
}