#include <stdio.h>
#include <math.h>

void swap(double* a,double* b){
	double temp = *a;
	*a = *b;
	*b = temp;
}
double a,b,c;
int n;

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%lf%lf%lf",&a,&b,&c);
		if(a>b){
			swap(&a,&b);
		}
		if(a>c){
			swap(&a,&c);
		}
		if(b>c){
			swap(&b,&c);
		}
		if(a+b > c){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
}