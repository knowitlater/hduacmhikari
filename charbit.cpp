//============================================================================
// Name        : charbit.cpp
// Author      : Hikari Vanish
// Version     :
// Copyright   : dszjs
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bitset>
using namespace std;
void printCharBit(char c) {
	for (int i = 7; i >= 0; i--) {
		cout << ((c & (1 << i)) ? 1 : 0);
	}
	cout << endl;
}
void printCharBit2(char c) {
	bitset<8> k(c);
	for (int i = 7; i >= 0; i--) {
		cout << (k[i] ? 1 : 0);
	}
	cout << endl;
}
int main() {
	char c;
	while (cin >> c) {
		printCharBit(c);
		printCharBit2(c);
	}
	return 0;
}
