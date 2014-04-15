#include <iostream>
#include <cmath>
using namespace std;
#define MOD 20100501
#define N 2000001
bool isNotPrime[N] = { 1, 1, 0 }; //even not sure!!!!!!!
unsigned int prime[N] = { 2 };
unsigned int primeLen = 1;
void primeInit() {
	unsigned int i, j, s;
	unsigned int len = (unsigned int) sqrt(N) + 1;
	for (i = 4; i <= N; i += 2)
		isNotPrime[i] = 1;
	for (i = 3; i < len; i += 2) {
		if (!isNotPrime[i]) {
			for (s = 2 * i, j = i * i; j < N; j += s) {
				isNotPrime[j] = 1;
			}
			prime[primeLen++] = i;
		}
	}
	for (; i < N; i += 2) {
		if (!isNotPrime[i]) {
			prime[primeLen++] = i;
		}
	}
}
unsigned char primeExp[N];
void mul(unsigned __int64 x) {
	unsigned __int64 k = 0;
	while (x > 1) {
		if (x % prime[k] == 0) {
			x /= prime[k];
			primeExp[k]++;
		} else {
			k++;
		}
	}
}
unsigned __int64 powMod(unsigned __int64 a, unsigned __int64 b,
		unsigned __int64 m) {
	unsigned __int64 ans = 1;
	while (b) {
		if (b & 1)
			ans = ans * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return ans;
}
//对某个数的阶乘分解质因数
void fac(unsigned __int64 t, unsigned __int64 temp) {
	unsigned __int64 tmp, i;
	for (i = 0; i < primeLen && prime[i] <= t; i++) {
		tmp = t;
		while (tmp) {
			if (temp == 0)
				primeExp[i] += tmp / prime[i];
			else
				primeExp[i] -= tmp / prime[i];
			tmp /= prime[i];
		}
	}
}
unsigned __int64 f(unsigned __int64 n, unsigned __int64 m) {
	unsigned __int64 i;
	unsigned __int64 res = 1;
	memset(primeExp, 0, sizeof(primeExp));
	fac(m + n, 0);
	fac(n + 1, 1);
	fac(m, 1);
	mul(n + 1 - m);
	for (i = 0; i < primeLen && prime[i] <= m + n; i++) {
		if (primeExp[i] > 0) {
			res = res * powMod(prime[i], primeExp[i], MOD) % MOD;

		}
	}
	return res;
}
unsigned __int64 m, n, T;
int main() {
	primeInit();
	cin >> T;
	while (T--) {
		cin >> n >> m;
		cout << f(n, m) << endl;
	}
}

