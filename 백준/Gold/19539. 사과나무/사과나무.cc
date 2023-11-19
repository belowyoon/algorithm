#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

	int n, t, sum = 0, sum_2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		sum += t;
		sum_2 += t / 2;

	}
	if (sum % 3 != 0) {
		cout << "NO";
		return 0;
	}
	
	string res = sum_2 >= (sum / 3)  ? "YES" : "NO";
	cout << res;
    return 0;
	
}
