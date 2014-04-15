#include <iostream>
using namespace std;

unsigned __int64 quickPow(int x, int n) {
	unsigned __int64 base = x, result = 1;
	while (n != 0) {
		if (n & 1) {
			result *= base;
		}
		n >>= 1;
		base *= base;
	}
	return result;
}
unsigned int quickPowMod(int x, int n, int c) {
	unsigned __int64 base = x % c, result = 1;
	while (n != 0) {
		if (n & 1) {
			result = base * result % c;
		}
		n >>= 1;
		base = (base * base) % c;
	}
	return (unsigned int) result;
}
#define N 100000
bool isNotPrime[N] = { 1, 1, 0 };
void init() {
	for (int i = 2; i * i < N; i++) {
		if (!isNotPrime[i]) {
			for (int j = i * i; j < N; j += 2 * i) {
				isNotPrime[j] = 1;
			}
		}
	}
}
bool isPrime(unsigned int d) {
	if (!(d & 1)) {
		return false;
	}
	for (int i = 3; i * i < d && i < N; i += 2) {
		if (!isNotPrime[i]) {
			if (d % i == 0) {
				return false;
			}
		}
	}
	return true;
}
int p, a;
int main() {
	init();
	while (cin >> p >> a && p && a) {
		if (!isPrime(p) && quickPowMod(a, p, p) == a) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
	return 0;
}
