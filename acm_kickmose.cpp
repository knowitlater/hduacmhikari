#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define K 11
#define T 21
int f[T][K];
int data[T][K];

int n,k;
int i,j;
int a,b,c,tmp;
int min;
int main(){
	while(scanf("%d%d",&n,&k) != EOF){
		for(i=0;i<n;i++){
			for(j=0;j<k;j++){
				scanf("%d",&data[i][j]);
			}
		}
		memset(f,0,sizeof(f));
		for(a=n-2;a>=0;a--){
			for(b=0;b<k;b++){
				f[a][b] = 1<<14;
				for(c=0;c<k;c++){
					tmp = abs(data[a][b]-data[a+1][c]) + f[a+1][c];
					if(f[a][b]>tmp){
						f[a][b] = tmp;
					}
				}
			}
		}
		min = 1<<14;
		for(i=0;i<k;i++){
			if(min >f[0][i]){
				min = f[0][i];
			} 
		}
		printf("%d\n",min);
	}
}