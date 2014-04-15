#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000001
int data[N];

int n,m,i;
int cmp(const void* a,const void* b){
	return *(int*)b - *(int*)a;
}
int main(){
	while(scanf("%d%d",&n,&m) == 2){
		for(i=0;i<n;i++){
			scanf("%d",data+i);
		}
		qsort(data,n,sizeof(data[0]),cmp);
		for(i=0;i<m-1;i++){
			printf("%d ",data[i]);
		}
		printf("%d\n",data[i]);

	}
}