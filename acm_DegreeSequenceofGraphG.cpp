#include <iostream>
#include <algorithm>
using namespace std;
int a[1000], b, T, N;
bool compare(int a, int b) {
	return a > b;
}
bool func() {
	for (int i = 0; i < b - 1; i++) {
		sort(a + i, a + b, compare);
		if (i + a[i] + 1 > b) {
			return false;
		}
		for (int j = i + 1; j <= i + a[i]; j++) {
			if (a[j] == 0) {
				return false;
			}
			a[j]--;
		}

	}
	if (a[b - 1] == 0)
		return true;
	else
		return false;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		b = N;
		while (N--) {
			cin >> a[N];
		}
		if (func()) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
	return 0;
}
