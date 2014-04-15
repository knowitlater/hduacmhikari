//============================================================================
// Name        : acm_gaigechunfeng.cpp
// Author      : Hikari Vanish
// Version     :
// Copyright   : dszjs
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

struct point {
	double x, y;
};
double area_polygon(int n, point* p) {
	double s1 = 0, s2 = 0;
	int i;
	for (i = 0; i < n; i++)
		s1 += p[(i + 1) % n].y * p[i].x, s2 += p[(i + 1) % n].y
				* p[(i + 2) % n].x;
	return fabs(s1 - s2) / 2;
}
#define N 101
point points[N];
int n, j, i;
int main() {
	while (1) {
		cin >> n;
		if (n == 0) {
			return 0;
		}
		for (i = 0; i < n; i++) {
			cin >> points[i].x >> points[i].y;
		}
		printf("%.1lf\n",area_polygon(n,points));
	}
	return 0;
}
