
#include <iostream>
using namespace std;

int extend_Eulid(int a, int b, int& x, int& y) {
	int d;
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	} else {
		d = extend_Eulid(b, a % b, x, y);
		int temp = x;
		x = y;
		y = temp - a / b * y;
	}
	return d;
}
int main() {
	int a, b, x, y;
	while (cin >> a >> b) {
		cout << extend_Eulid(a, b, x, y) << " " << x << " " << y << endl;
	}
	return 0;
}
