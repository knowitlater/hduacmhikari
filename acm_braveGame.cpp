#include <iostream>
using namespace std;
int T, n, m;
int main() {
	cin >> T;
	while (T--) {
		cin >> n >> m;
		if (n % (m + 1) == 0) {
			cout << "second" << endl;
		} else {
			cout << "first" << endl;
		}
	}
	return 0;
}
