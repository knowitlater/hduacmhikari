#include <stdio.h>

#define N 1000
unsigned long f[N];

void init(){
	int i;
	for(i=1;i<N;i++){
		if(i%2==0){
			f[i]=i*i;
		}else{
			f[i] = i*i*i;
		}
	}
}
int x,y,a,b,i;
int main(){
	init();
	while(scanf("%d%d",&x,&y)!=EOF){
		if(x>y){
			x^=y^=x^=y;
		}
		a=0;b=0;
		for(i=x;i<=y;i++){
			if(i%2==0){
				a+=f[i];
			}else{
				b+=f[i];
			}
		}
		printf("%d %d\n",a,b);
	}
	return 0;
}