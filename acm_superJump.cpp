#include <stdio.h>

#define N 1002
unsigned __int64 f[2][N];


int n;
int i,j;
unsigned __int64 max,k;
int main(){
	while(1){
		scanf("%d",&n);
		if(n==0){
			return 0;
		}
		for(i=0;i<n;i++){
			scanf("%I64d",&f[0][i]);
			f[1][i] = f[0][i];
		}
		max = f[0][0];
		for(i=1;i<n;i++){
			for(j=i-1;j>=0;j--){
				if((f[0][i] > f[0][j])&&(f[1][i] < f[1][j] + f[0][i])){
					f[1][i] = f[1][j] + f[0][i];
				}
			}
			if(f[1][i] > max){
				max = f[1][i];
			}
		}
		printf("%I64d\n",max);
	}
}