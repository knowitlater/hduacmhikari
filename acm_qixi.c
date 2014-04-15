/*
 ============================================================================
 Name        : acm_qixi.c
 Author      : Hikari Vanish
 Version     :
 Copyright   : dszjs
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 500001
unsigned __int64 f[N];
void init() {
	int k, j;
	for (j = 2; j < N / 2 + 1; j++) {
		for (k = j * 2; k < N; k += j) {
			f[k] += j;
		}
	}

}
int T, n;
int main(void) {
	init();
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		printf("%I64u\n", f[n] + 1);
	}
	return EXIT_SUCCESS;
}
