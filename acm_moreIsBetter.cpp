#include <stdio.h>
typedef struct {
	int parent;
	int number;
} Node;
#define N 10000001

Node ds[N];
int n, i, j, k;
int a, b, aa, bb;
int tmp1,tmp2, maxcc;
int find(int x) {
	tmp1 = x;
	while (x != ds[x].parent) {
		x = ds[x].parent;
	}
	while (tmp1 != x) {
		tmp2 = tmp1;
		tmp1 = ds[tmp1].parent;
		ds[tmp2].parent = x;
	}
	return x;
}
int main() {
	while (scanf("%d",&n)!=EOF) {
		for (i = 0; i < N; i++) {
			ds[i].parent = i;
			ds[i].number = 1;
		}
		maxcc = 1;
		while (n--) {
			scanf("%d%d",&a,&b);
			aa = find(a - 1);
			bb = find(b - 1);
			if (aa != bb) {
				ds[aa].number += ds[bb].number;
				ds[bb].parent = aa;
				if (ds[aa].number > maxcc) {
					maxcc = ds[aa].number;
				}
			}
		}
		printf("%d\n",maxcc);
	}
	return 0;
}





//
//#include <stdio.h>
//
//struct Node{
//    int pre;
//    int rank;
//}tree[10000005];
//int maxn;
//
//int Find(int x){
//    int p = x;
//    while(tree[p].pre != p){
//        p = tree[p].pre;
//    }
//    int i = x;
//    while(i != p){
//        int j = tree[i].pre;
//        tree[i].pre = p;
//        i = j;
//    }
//    return p;
//}
//
//void Join(int x,int y){
//    int fx = Find(x);
//    int fy = Find(y);
//    if(fx != fy){
//        tree[fy].rank += tree[fx].rank;
//        if(tree[fy].rank > maxn){
//            maxn = tree[fy].rank;
//        }
//        tree[fx].pre = fy;
//    }
//}
//
//int main(){
//    int n;
//    int i,j;
//    int x,y;
//
//    while(scanf("%d",&n) != EOF){
//        maxn = 1;
//        for(i = 0;i < 10000005;i++){
//            tree[i].pre = i;
//            tree[i].rank = 1;
//        }
//        for(i = 0;i < n;i++){
//            scanf("%d%d",&x,&y);
//            Join(x,y);
//        }
//        printf("%d\n",maxn);
//    }
//    return 0;
//}

