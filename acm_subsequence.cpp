#include <stdio.h>
#include <string.h>

#define N 1000

int f[N+1][N+1]={0};
char s1[N];
char s2[N];
int main(){
	while(scanf("%s%s",s1,s2) == 2){
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		for(int i=1;i<=len1;i++){
			for(int j=1;j<=len2;j++){
				if(s1[i-1] == s2[j-1]){
					f[i][j] = f[i-1][j-1] + 1;
				}else{
					f[i][j] = f[i-1][j] > f[i][j-1]?f[i-1][j]:f[i][j-1];
				}
			}
		}
		printf("%d\n",f[len1][len2]);
	}
}