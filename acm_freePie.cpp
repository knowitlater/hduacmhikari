#include <stdio.h>
#include <string.h>

#define N 100002

int f[N][13];

int n,x,T,i,maxT=0,j;
inline int cmax(int a,int b,int c){
	return a>b?(a>c?a:c):(b>c?b:c);
}
int main(){
	
	while(scanf("%d",&n) != EOF){
		if(n==0){
			return 0;
		}
		memset(f,0,sizeof(f));
		for(i=0;i<n;i++){
			scanf("%d%d",&x,&T);
			f[T][x+1]++;
			if(T > maxT){
				maxT =T;
			}
		}
		for(i=maxT-1;i>=0;i--){
			for(j=1;j<=11;j++){
				f[i][j] += cmax(f[i+1][j-1],f[i+1][j],f[i+1][j+1]);
			}
		}
		printf("%d\n",f[0][6]);
	}
}