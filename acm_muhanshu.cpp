#include <iostream>
using namespace std;
const int lmax = 300;
int c1[lmax + 1], c2[lmax + 1];
int main(void) {
	int n, i, j, k;
	int elem[17] = {  };//��i�����ŵ��ݵ�������
	while (cin >> n && n != 0) {//n��Ҫ�ָ��������ͬʱҲ��ѭ���ı߽�
		for (i = 0; i <= n; i++) {
			c1[i] = 1;//c1���ȱ�����ǵ�һ�����ŵ�ϵ��
			c2[i] = 0;//c2����ʱ������
		}
		for (i = 2; i <= 17; i++) {//�ӵڶ������ŵ���17������
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
