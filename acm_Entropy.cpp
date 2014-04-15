#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
string s;
map<char, int> m;
int i;
int tmp;
int sum;
priority_queue<int, vector<int>, greater<int> > pq;
int main() {
	while (cin >> s && s != "END") {
		m.clear();
		for (i = 0; i < s.length(); i++) {
			m[s[i]]++;
		}
		for (map<char, int>::iterator iter = m.begin(); iter != m.end();
				++iter) {
			pq.push(iter->second);
		}
		if (pq.size() > 1) {
			sum = 0;
			while (pq.size() > 1) {
				tmp = pq.top();
				pq.pop();
				tmp += pq.top();
				pq.pop();
				pq.push(tmp);
				sum += tmp;
			}
		} else {
			sum = pq.top();
		}
		pq.pop();
		printf("%d %d %.1f\n", s.length() * 8, sum, s.length() * 8.0 / sum);
	}
}

