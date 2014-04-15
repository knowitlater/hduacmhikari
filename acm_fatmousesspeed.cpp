#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1004 
int f[N];
typedef struct{
	int frontIndex;
	int id;
	int weight;
	int speed;
} Mouse;
Mouse mouses[N];

int stack[N];int top=0;
int max,maxIndex;
int j,k;
int cmp(const void* aa,const void* bb){
	return ((Mouse*)aa)->weight-((Mouse*)bb)->weight;
}
int a,b;
int main(){
	int i=0,kkk;
	while(scanf("%d%d",&a,&b)!= EOF){
		mouses[i].weight = a;
		mouses[i].speed = b;
		mouses[i].id = i+1;
		i++;
	}
	qsort(mouses,i,sizeof(mouses[0]),cmp);
	max = 0-1;
	for(j=0;j<i;j++){
		mouses[j].frontIndex = j;
		for(k=j-1;k>=0;k--){
			if(mouses[j].speed < mouses[k].speed &&mouses[j].weight !=mouses[k].weight){
				if(f[k]+1 > f[j]){
					f[j] = f[k] + 1;
					mouses[j].frontIndex = k;
				}
			}
		}
		if(f[j] > max){
			max = f[j];
			maxIndex = j;
		}
	}
	printf("%d\n",max+1);
	top = 0;
	while(mouses[maxIndex].frontIndex != maxIndex){
		stack[top++] = mouses[maxIndex].id;
		maxIndex = mouses[maxIndex].frontIndex;
	}
	stack[top++] = mouses[maxIndex].id;
	while(top--){
		printf("%d\n",stack[top]);
	}
	

}