//============================================================================
// Name        : BigNumberTestMine2.cpp
// Author      : Hikari Vanish
// Version     :
// Copyright   : dszjs
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define MAXLEN 200
typedef struct {
	int len;
	int data[MAXLEN];
} BigNumber;
void mul(BigNumber& c, const BigNumber& a, const BigNumber& b) {
	int i, j;
	memset(&c, 0, sizeof(BigNumber));
	for (c[0] = a[0] + b[0] - 1, i = 1; i <= a[0]; i++)
		for (j = 1; j <= b[0]; j++)
			if ((c[i + j - 1] += a[i] * b[j]) >= DEPTH)
				c[i + j] += c[i + j - 1] / DEPTH, c[i + j - 1] %= DEPTH;
	for (c[0] += (c[c[0] + 1] > 0); !c[c[0]] && c[0] > 1; c[0]--)
		;
}
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
