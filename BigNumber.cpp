/*
 * BigNumber.cpp
 *
 *  Created on: 2013Äê12ÔÂ2ÈÕ
 *      Author: LENOVO
 */

#include "BigNumber.h"

BigNumber::BigNumber() {
	*this = BigNumber(string("0"));

}
BigNumber::BigNumber(string s) {
	int len = s.size();
	d[0] = (len - 1) / 4 + 1;
	int i, j, k;
	for (i = 1; i < maxl; i++)
		d[i] = 0;
	for (i = len - 1; i >= 0; --i) {
		j = (len - i - 1) / 4 + 1;
		k = (len - i - 1) % 4;
		d[j] += ten[k] * (s[i] - '0');
	}
	while (d[0] > 1 && d[d[0]] == 0)
		--d[0];
}
string  BigNumber:: toString() {
	string s("");
	int i, j, temp;
	for (i = 3; i >= 1; --i)
		if (d[d[0]] >= ten[i])
			break;
	temp = d[d[0]];
	for (j = i; j >= 0; --j) {
		s += (char) (temp / ten[j] + '0');
		temp %= ten[j];
	}
	for (i = d[0] - 1; i > 0; --i) {
		temp = d[i];
		for (j = 3; j >= 0; --j) {
			s += (char) (temp / ten[j] + '0');
			temp %= ten[j];
		}
	}
	return s;
}
BigNumber::~BigNumber() {
	// TODO Auto-generated destructor stub
}

