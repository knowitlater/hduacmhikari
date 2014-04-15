#include <iostream>
using namespace std;
const int lmax = 300;
int c1[lmax + 1], c2[lmax + 1];
int main(void) {
	int n, i, j, k;
	int elem[17] = {  };//第i个括号的幂的增加量
	while (cin >> n && n != 0) {//n是要分割的总量，同时也是循环的边界
		for (i = 0; i <= n; i++) {
			c1[i] = 1;//c1最先保存的是第一个括号的系数
			c2[i] = 0;//c2是临时的数组
		}
		for (i = 2; i <= 17; i++) {//从第二个括号到第17个括号
			for (j = 0; j <= n; j++)
				for (k = 0; k + j <= n; k += elem[i - 1]) {
					c2[j + k] += c1[j];
				}
			for (j = 0; j <= n; j++) {
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		cout << c1[n] << endl;
	}
	return 0;
}
