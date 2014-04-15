#include <stdio.h>
#include <string.h>
#define N 5843
int kk[]={2,3,5,7};
unsigned __int64 temp;
unsigned __int64 humbleNumbers[N]={0,1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27};
void init(){
	for(int i=20;i<N;i++){
		humbleNumbers[i]= 2000000000;
		for(int j=1;j<i-1;j++){
			for(int k=0;k<4;k++){
				if((temp=humbleNumbers[j]*kk[k]) > humbleNumbers[i-1]){
					if(temp< humbleNumbers[i]){
						humbleNumbers[i] = temp;
						break;
					}

				}
			}
		}

	}
}
int n;
char s[4];
int main(){
	init();
	while(1){
		scanf("%d",&n);
		if(n==0){
			return 0;
		}
		if(n%10==1&&n%100!=11){
			strcpy(s,"st");
		}
        else if(n%10==2&&n%100!=12){
			strcpy(s,"nd");
		}
        else if(n%10==3&&n%100!=13){
			strcpy(s,"rd");
		}
        else  {
			strcpy(s,"th");
		}
		printf("The %i%s humble number is %I64u.\n",n,s,humbleNumbers[n]);
	}
}