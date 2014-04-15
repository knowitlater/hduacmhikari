#include <stdio.h>
#define N 55
__int64 f[N]={1,3,7,5};
void init(){
	for(int i = 4;i<N;i++){
		f[i] = 2*f[i-2]+ f[i-1];
	}
}
int n,T;
int main(){
	init();
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==0){
			return 0;
		}
		printf("%I64d\n",f[n]);
	}
}