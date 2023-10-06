#include <iostream>
#include <algorithm>
using namespace std;

long long a, b, c;

long long int cal(long long b) {
    if (b == 0) return 1;
	if (b == 1) return a % c;
	
	long long k = cal(b / 2) % c;
	if (b % 2 == 0) return k * k % c;
	else return (k * k % c) * (a % c);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> a >> b >> c;
    cout << cal(b) % c;

    return 0;
}