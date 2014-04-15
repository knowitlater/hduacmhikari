#include <stdio.h>

#define N 10001
unsigned long f[N];
void init(){
	unsigned long i,j,k=0;
	for(i=1;i<N/2+1;i++){
		for(j=i*2;j<N;j+=i){
			f[j]+=i;
		}
		if(i==f[i]){
			k++;
		}
		f[i] = k;
	}
	for(;i<N;i++){
		if(i==f[i]){
			k++;
		}
		f[i] = k;
	}
}
int n,num1,num2;
int main(){
	init();
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&num1,&num2);
		if(num1>num2){
			num1^=num2^=num1^=num2;
		}
		printf("%d\n",f[num2]-f[num1-1]);
	}
	return 0;
}
