#include <iostream>
#include <cstring>
using namespace std;
#define N 202
int room[N];
int T, n, a, b, maxc;
int main() {
	cin >> T;
	while (T--) {
		memset(room, 0, sizeof(room));
		maxc = 0;
		cin >> n;
		while (n--) {
			cin >> a >> b;
			if (b < a) {
				a ^= b ^= a ^= b;
			}
			for (int i = (a - 1) / 2; i <= (b - 1) / 2; i++) {
				room[i]++;
			}

		}
		for (int i = 0; i < 200; i++) {
			if (room[i] > maxc) {
				maxc = room[i];
			}
		}
		cout << maxc * 10 << endl;
	}
	return 0;
}
