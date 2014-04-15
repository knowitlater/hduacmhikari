#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 12
int re[N][N];
struct ss{
	int index;
	int neighbor;
};
ss aa[N];
int T,n,i,temp,j;
bool cmp(const ss& a,const ss& b){
	return a.neighbor < b.neighbor;
}
bool ok = false;
int main(){
	cin >> T;
	while(T--){
		cin >> n;
		for(i =0;i<n;i++){
			cin >> temp;
			aa[i].index = i;
			aa[i].neighbor = temp;
		}

		memset(re,0,sizeof(re));
		int k= n;ok = true;
		while(k-->1){
			sort(aa,aa+k+1,cmp);
			if(aa[k].neighbor > k){
				ok = false;
				break;
			}else{
				for(j=k-1;j>=k-aa[k].neighbor;j--){
					if(aa[j].neighbor > 0){
						aa[j].neighbor--;
						re[aa[k].index][aa[j].index]=re[aa[j].index][aa[k].index] = 1;
					}else{
						ok = false;
						break;
					}
				}
			}
		}
		if(ok && (aa[0].neighbor==0)){
			cout << "YES" << endl;
			for(i=0;i<n;i++){
				for(j=0;j<n-1;j++){
					cout <<	re[i][j] << " ";	
				}
				cout << re[i][j] << endl;
			}
		}else{
			cout << "NO" << endl;
		}
		if(T){
			cout << endl;
		}
	}
}