#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <vector>
using namespace std;
int n, nn;
map<string, int> mp;
string s;
int m;
int a;
int i, j;
int k;
int cnt;
int main() {
	while (cin >> n) {
		mp.clear();
		nn = n;
		while (nn--) {
			cin >> s;
		}
		cin >> m;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				cin >> a >> s;
				mp[s] += a;
			}
			k = mp["memory"];
			cnt = 0;
			for (map<string, int>::iterator iter = mp.begin(); iter != mp.end();
					++iter) {
				if (iter->second > k) {
					cnt++;
				}
			}
			cout << cnt + 1 << endl;
		}
	}
	return 0;
}
