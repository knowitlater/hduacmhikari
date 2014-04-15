
#include <iostream.h>
#include <string.h>

#define DIGIT	4
#define DEPTH	10000
#define MAX     100
typedef int bignum_t[MAX+1];

void write(const bignum_t a,ostream& os=cout){
	int i,j;
	for (os<<a[i=a[0]],i--;i;i--)
		for (j=DEPTH/10;j;j/=10)
			os<<a[i]/j%10;
}
void add(bignum_t a,const bignum_t b){
	int i;
	for (i=1;i<=b[0];i++)
		if ((a[i]+=b[i])>=DEPTH)
			a[i]-=DEPTH,a[i+1]++;
	if (b[0]>=a[0])
		a[0]=b[0];
	else
		for (;a[i]>=DEPTH&&i<a[0];a[i]-=DEPTH,i++,a[i]++);
	a[0]+=(a[a[0]+1]>0);
}

#define N 1002
bignum_t ff[N]={{1,1},{1,1},{1,2},{1,4},{1,7}};
int n;
void init(){
	for(int i=5;i<N;i++){
		add(ff[i],ff[i-1]);
		add(ff[i],ff[i-2]);
		add(ff[i],ff[i-4]);
	}
}
int main(){
	init();
	while(cin>> n){
		write(ff[n]);
		cout << endl;
	}
}