#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> line;

long long division(int length) {
    long long sum = 0;
    for (long long i = 0; i < line.size(); i++) {
        sum += line[i]/length;
    }
    return sum;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long k, n;
    cin >> k >> n;
    long long sum = 0;

    for (long long i = 0; i < k; i++){
        long long length;
        cin >> length;
        line.push_back(length);
        sum += length;
    }
    sort(line.begin(), line.end());

    long long l = 1, answer = 0, r = line[line.size()-1];
    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        if (mid == 0)
            mid = 1;
        long long num = division(mid);
        if (num < n) {
            r = mid - 1;
            answer = mid -1;
        } else {
            l = mid + 1;
            answer = mid;
        }
    }
    cout << answer;
    return 0;
}