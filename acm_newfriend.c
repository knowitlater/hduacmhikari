/*
 ============================================================================
 Name        : acm_newfriend.c
 Author      : Hikari Vanish
 Version     :
 Copyright   : dszjs
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int eular(int n) {
	int ret = 1, i;
	for (i = 2; i * i <= n; i++)
		if (n % i == 0) {
			n /= i, ret *= i - 1;
			while (n % i == 0)
				n /= i, ret *= i;
		}
	if (n > 1)
		ret *= n - 1;
	return ret;
}
int CN,n;
int main(void) {
	scanf("%d",&CN);
	while(CN--){
		scanf("%d",&n);
		printf("%d\n",eular(n));
	}
	return EXIT_SUCCESS;
}
