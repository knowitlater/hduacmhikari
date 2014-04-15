//#include <iostream>
//#include <cstring>
//using namespace std;
//
//#define DIGIT   4
//#define DEPTH   10000
//#define MAX     100
//typedef int bignum_t[MAX + 1];
//void write(const bignum_t a, ostream&os = cout) {
//	int i, j;
//	for (os << a[i = a[0]], i--; i; i--)
//		for (j = DEPTH / 10; j; j /= 10)
//			os << a[i] / j % 10;
//}
//void mul(bignum_t c, const bignum_t a, const bignum_t b) {
//	int i, j;
//	memset((void*) c, 0, sizeof(bignum_t));
//	for (c[0] = a[0] + b[0] - 1, i = 1; i <= a[0]; i++)
//		for (j = 1; j <= b[0]; j++)
//			if ((c[i + j - 1] += a[i] * b[j]) >= DEPTH)
//				c[i + j] += c[i + j - 1] / DEPTH, c[i + j - 1] %= DEPTH;
//	for (c[0] += (c[c[0] + 1] > 0); !c[c[0]] && c[0] > 1; c[0]--)
//		;
//}
//void mul(bignum_t a, const int b) {
//	int i;
//	for (a[1] *= b, i = 2; i <= a[0]; i++) {
//		a[i] *= b;
//		if (a[i - 1] >= DEPTH)
//			a[i] += a[i - 1] / DEPTH, a[i - 1] %= DEPTH;
//	}
//	for (; a[a[0]] >= DEPTH;
//			a[a[0] + 1] = a[a[0]] / DEPTH, a[a[0]] %= DEPTH, a[0]++)
//		;
//	for (; !a[a[0]] && a[0] > 1; a[0]--)
//		;
//}
//void div(bignum_t a, const int b) {
//	int i, c;
//	for (c = 0, i = a[0]; i; c = c * DEPTH + a[i], a[i] = c / b, c %= b, i--)
//		;
//	for (; !a[a[0]] && a[0] > 1; a[0]--)
//		;
//}
//#define N 101
//bignum_t catalan[N] = { 0 };
//void catalanInit() {
//	catalan[0][0] = 1;
//	catalan[0][1] = 1;
//	for (int i = 1; i < N; i++) {
//		memcpy(catalan[i], catalan[i - 1], sizeof(catalan[0]));
//		mul(catalan[i], 4 * i - 2);
//		div(catalan[i], i + 1);
//	}
//}
//bignum_t factorial[N] = { 0 };
//void factorialInit() {
//	factorial[0][0] = 1;
//	factorial[0][1] = 1;
//	for (int i = 1; i < N; i++) {
//		memcpy(factorial[i], factorial[i - 1], sizeof(factorial[0]));
//		mul(factorial[i], i);
//	}
//}
//int n;
//bignum_t tmp;
//int main() {
//	catalanInit();
//	factorialInit();
//	while (cin >> n && n != 0) {
//		mul(tmp, catalan[n], factorial[n]);
//		write(tmp);
//		cout << endl;
//	}
//	return 0;
//}

#include <iostream>
using namespace std;

#define N 21
unsigned __int64 f[N][N]={0};
void init() {
	int i, j;
	for (i = 0; i < N; i++) {
		f[0][i] = 1;
	}
	for (i = 1; i < N; i++) {
		for (j = i; j < N; j++) {
			f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
	}
}
int m, n;
int main() {
	init();
	while (cin >> m >> n) {
		cout << f[n][m] << endl;
	}

}

