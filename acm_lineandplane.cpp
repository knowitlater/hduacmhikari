#include <stdio.h>

int C,n;
int main(){
	scanf("%d",&C);
	while(C--){
		scanf("%d",&n);
		printf("%I64d\n",n*n*2 -n +1);
	}
}