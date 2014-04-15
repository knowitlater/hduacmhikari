	#include <stdio.h>

	int fn0=-1,fn1;
	int T,n,i;
	int start,end,starttemp;
	int temp,max=0-1<<14;
	int t;
	int main(){
		scanf("%d",&T);
		for(t=1;t<=T;t++){
			scanf("%d",&n);
			start = end = 1;
			max =0-1<<14;
			fn0 = -1;
			for(i=1;i<=n;i++){
				scanf("%d",&temp);
				if(fn0 <0){
					fn1 = temp;
					starttemp = i;
				}else{
					fn1 = fn0+ temp;
				}
				if(max < fn1){
					max = fn1;	
					start = starttemp;
					end = i;
				}
				fn0 = fn1;
			}
			printf("Case %d:\n%d %d %d\n",t,max,start,end);
			if(t<T){
				printf("\n");
			}

		}
		
	}