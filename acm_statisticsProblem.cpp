#include <stdio.h>

#define N 22
int C;
unsigned __int64 f[N]={1,3,7};
void init(){
	for(int i= 3;i<N;i++){
		f[i] = f[i-1]*2 + f[i-2];
	}
}
int n;
int main(){
	init();
	scanf("%d",&C);
	while( C--){
		scanf("%d",&n);
		printf("%I64d\n",f[n]);
	}
}