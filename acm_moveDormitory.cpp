#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 2003
#define cmin(A,B) (((A)>(B))?(B):(A))
int data[N];
 unsigned __int64 f[1003][N];
int n, k;
int i,j,d;
int cmp(const void * a, const void* b){
	return (int)(*(unsigned  __int64 *)a - *(unsigned  __int64 *)b);
}
int main() {
	while (scanf("%d%d",&n,&k) == 2) {
		for (int i = 0; i < n; i++) {
			scanf("%d",data+i);
		}
		qsort(data, n,sizeof(data[0]),cmp);
		memset(f[0], 0, sizeof(f[0]));
		for (i = 1; i <= k; i++) {
			for (j = 0; j < n; j++) {
			if (i * 2 == j + 1) {
					f[i][j] = 0;
					for (d = 0; d <= j - 1; d += 2) {
						f[i][j] += (data[d] - data[d + 1])
								* (data[d] - data[d + 1]);
					}
				} else if(i*2 < j+1){
					f[i][j] = cmin(f[i - 1][j - 2]+ (data[j] - data[j - 1])* (data[j] - data[j - 1]),f[i][j - 1]);
				}
			}
		}
		printf("%I64u\n",f[k][n-1]);
	}
	return 0;
}
