#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct Point{
	double x,y;
};
#define N 100004
struct Point pp[N];
double a,b;
int n,i,j;
int cmpx(const void* aaa,const void* bbb){
	struct Point *ak  = (struct Point *)aaa;
	struct Point *bk  = (struct Point *)bbb;
	return (ak->x - bk->x )> 0.1? 1:0;
}
int cmpy(const void* aaa,const void* bbb){
	struct Point *ak  = (struct Point *)aaa;
	struct Point *bk  = (struct Point *)bbb;
	return (ak->y - bk->y )> 0? 1:0;
}
int cmpxy(const void* aaa,const void* bbb){
	struct Point *ak  = (struct Point *)aaa;
	struct Point *bk  = (struct Point *)bbb;
	return (ak->x - bk->x +ak->y-bk->y)> 0? 1:0;
}
int cmpyx(const void* aaa,const void* bbb){
	struct Point *ak  = (struct Point *)aaa;
	struct Point *bk  = (struct Point *)bbb;
	return (ak->x - bk->x +ak->y-bk->y)> 0? 1:0;
}
#define P 8
double min,mintemp;
int main(){
	while(1){
		scanf("%d",&n);
		if(n==0){
			return 0;
		}
		for(i=0;i<n;i++){
			scanf("%lf%lf",&a,&b);
			pp[i].x = a;
			pp[i].y = b;
		}
		qsort(pp,n,sizeof(pp[0]),cmpx);
		min = 10000000;
	
		for(i=0;i<n-1;i++){
			for(j=i+1;j<(n>(i+P+1)?i+P+1:n);j++){
				mintemp = hypot(pp[i].x-pp[j].x,pp[i].y-pp[j].y);
				if(mintemp < min){
					min = mintemp;
				}
			}
		}
			qsort(pp,n,sizeof(pp[0]),cmpy);
			for(i=0;i<n-1;i++){
			for(j=i+1;j<(n>(i+P+1)?i+P+1:n);j++){
				mintemp = hypot(pp[i].x-pp[j].x,pp[i].y-pp[j].y);
				if(mintemp < min){
					min = mintemp;
				}
			}
		}
		printf("%.2f\n",min/2);
	
	}
}