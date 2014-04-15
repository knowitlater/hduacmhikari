#include <stdio.h>



int t,a,b;
char c;
int main(){
	scanf("%d",&t);
	while(t--){
		getchar();
		c = getchar();
		scanf("%d%d",&a,&b);
		switch(c){
		case '+':
			printf("%d\n",a+b);
			break;
		case '-': 
			printf("%d\n",a-b);
			break;
		case '*':
			printf("%d\n",a*b);
			break;
		case '/':
			if(a%b==0){
				printf("%d\n",a/b);
			}else{
				printf("%.2lf\n",((double)a)/b);
			}
		}
	}
}