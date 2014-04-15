#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAXN 1000
#define offset 10000
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
struct point {
	double x, y;
};
struct line {
	point a, b;
};
double xmult(point p1, point p2, point p0) {
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
//graham算法顺时针构造包含所有共线点的凸包,O(nlogn)
point p1, p2;
int graham_cp(const void* a, const void* b) {
	double ret = xmult(*((point*) a), *((point*) b), p1);
	return zero(ret) ?
			(xmult(*((point*) a), *((point*) b), p2) > 0 ? 1 : -1) :
			(ret > 0 ? 1 : -1);
}
void _graham(int n, point* p, int& s, point* ch) {
	int i, k = 0;
	for (p1 = p2 = p[0], i = 1; i < n; p2.x += p[i].x, p2.y += p[i].y, i++)
		if (p1.y - p[i].y > eps || (zero(p1.y-p[i].y) && p1.x > p[i].x))
			p1 = p[k = i];
	p2.x /= n, p2.y /= n;
	p[k] = p[0], p[0] = p1;
	qsort(p + 1, n - 1, sizeof(point), graham_cp);
	for (ch[0] = p[0], ch[1] = p[1], ch[2] = p[2], s = i = 3; i < n; ch[s++] =
			p[i++])
		for (; s > 2 && xmult(ch[s - 2], p[i], ch[s - 1]) < -eps; s--)
			;
}

//构造凸包接口函数,传入原始点集大小n,点集p(p原有顺序被打乱!)
//返回凸包大小,凸包的点在convex中
//参数maxsize为1包含共线点,为0不包含共线点,缺省为1
//参数clockwise为1顺时针构造,为0逆时针构造,缺省为1
//在输入仅有若干共线点时算法不稳定,可能有此类情况请另行处理!
//不能去掉点集中重合的点
int graham(int n, point* p, point* convex, point* temp, int maxsize = 1,
		int dir = 1) {
	//point* temp = new point[n];
	int s, i;
	_graham(n, p, s, temp);
	for (convex[0] = temp[0], n = 1, i = (dir ? 1 : (s - 1)); dir ? (i < s) : i;
			i += (dir ? 1 : -1))
		if (maxsize || !zero(xmult(temp[i - 1], temp[i], temp[(i + 1) % s])))
			convex[n++] = temp[i];
	//delete[] temp;
	return n;
}
double mydistance(point a, point b) {
	return sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
}
#define N 101
point points[N];
point convexPoints[N];
point tmp[N];
int n, j, i, size;
double length;
int main() {
	while (1) {
		cin >> n;
		if (n == 0) {
			return 0;
		}
		for (i = 0; i < n; i++) {
			cin >> points[i].x >> points[i].y;
		}
		size = graham(n, points, convexPoints,tmp, 0, 0);
		length = 0;
		for (i = 0; i < size - 1; i++) {
			length += mydistance(convexPoints[i], convexPoints[i + 1]);
		}
		length += mydistance(convexPoints[0], convexPoints[size - 1]);
		printf("%.2lf\n", length);
	}
	return 0;
}
