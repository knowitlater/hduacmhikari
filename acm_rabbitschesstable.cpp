#include <stdio.h>
#include <iostream.h>
#include <string.h>

#define DIGIT	4
#define DEPTH	10000
#define MAX     100
typedef int bignum_t[MAX+1];
void write(const bignum_t a,ostream& os=cout){
	int i,j;
	for (os<<a[i=a[0]],i--;i;i--)
		for (j=DEPTH/10;j;j/=10)
			os<<a[i]/j%10;
}




#define N 36
unsigned __int64 f[N] = {1, 1, 2, 5, 14};
void init(){
	int i;
	for(i=3;i<N;i++){
		f[i] = f[i-1]*(4*i-2)/(i+1);
	}
}

int i=1,n;
int main(){
	init();
	while(1){
		scanf("%d",&n);
		if(n == -1){
			return 0;
		}
		if(n<35){
			printf("%d %d %I64u\n",i++,n,f[n]*2);
		}else{
			printf("%d %d 476490352453858341\n",i++,n);
		}
		
	}
}d