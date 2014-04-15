//============================================================================
// Name        : acm_ShellPyramid.cpp
// Author      : Hikari Vanish
// Version     :
// Copyright   : dszjs
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned __int64 LL;

int a, b, c, n, m;
LL s;
int tmp;
int i;
int main() {
	cin >> n;
	while (n--) {
		cin >> s;
		i = pow(s * 6.0, 1.0 / 3) - 2;
		while ((tmp = (i * (2 + i * (3 + i))) - s) < 0) {
			i++;
		}
}
return 0;
}
