#include <iostream>
using namespace std;
unsigned __int64 qm(unsigned __int64 a, unsigned __int64 b,
		unsigned __int64 n) {
	unsigned __int64 res = 1, tmp = a;
	while (b) {
		if (b & 1) {
			res = res * tmp % n;
		}
		tmp = tmp * tmp % n;
		b >>= 1;
	}
	return res;
}
int a, b;
int t;
int main() {
	cin >> t;
	while (t--) {
		cin>> a;
		cout << qm(a, a, 10) << endl;
	}
	return 0;
}
