#include <iostream>
#include <string>
#include <sstream>
#include <set>
using namespace std;

char line[100000];
string s;
set<string> st;
int main() {
	while (1) {
		cin.getline(line, sizeof(line) / sizeof(line[0]));
		istringstream is(line);
		st.clear();
		while (is >> s) {
			if (s == "#")
				return 0;
			st.insert(s);
		}
		cout << st.size() << endl;
	}
	return 0;
}
