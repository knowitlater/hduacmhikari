#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;
#define MAXN 9999
#define MAXSIZE 10
#define DLEN 4
class BigNum {
private:
	int a[500];    
	int len;     
public:
	BigNum() {
		len = 1;
		memset(a, 0, sizeof(a));
	}  
	BigNum(const int);      
	BigNum(const char*);  
	BigNum(const BigNum &);

	friend ostream& operator<<(ostream&, BigNum&);

	BigNum operator*(const BigNum &) const;
	BigNum operator/(const int &) const;

};
BigNum::BigNum(const int b)
		{
	int c, d = b;
	len = 0;
	memset(a, 0, sizeof(a));
	while (d > MAXN) {
		c = d - (d / (MAXN + 1)) * (MAXN + 1);
		d = d / (MAXN + 1);
		a[len++] = c;
	}
	a[len++] = d;
}
BigNum::BigNum(const char*s)     //将一个字符串类型的变量转化为大数
		{
	int t, k, index, l, i;
	memset(a, 0, sizeof(a));
	l = strlen(s);
	len = l / DLEN;
	if (l % DLEN)
		len++;
	index = 0;
	for (i = l - 1; i >= 0; i -= DLEN)
	{
		t = 0;
		k = i - DLEN + 1;
		if (k < 0)
			k = 0;
		for (int j = k; j <= i; j++)
			t = t * 10 + s[j] - '0';
		a[index++] = t;
	}
}
BigNum::BigNum(const BigNum & T) :
		len(T.len)
{
	int i;
	memset(a, 0, sizeof(a));
	for (i = 0; i < len; i++)
		a[i] = T.a[i];
}

ostream& operator<<(ostream& out, BigNum& b)
		{
	int i;
	cout << b.a[b.len - 1];
	for (i = b.len - 2; i >= 0; i--) {
		cout.width(DLEN);
		cout.fill('0');
		cout << b.a[i];
	}
	return out;
}

BigNum BigNum::operator*(const BigNum & T) const
		{
	BigNum ret;
	int i, j, up;
	int temp, temp1;
	for (i = 0; i < len; i++) {
		up = 0;
		for (j = 0; j < T.len; j++) {
			temp = a[i] * T.a[j] + ret.a[i + j] + up;
			if (temp > MAXN) {
				temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);
				up = temp / (MAXN + 1);
				ret.a[i + j] = temp1;
			} else {
				up = 0;
				ret.a[i + j] = temp;
			}
		}
		if (up != 0)
			ret.a[i + j] = up;
	}
	ret.len = i + j;
	while (ret.a[ret.len - 1] == 0 && ret.len > 1)
		ret.len--;
	return ret;
}
BigNum BigNum::operator/(const int & b) const 
		{
	BigNum ret;
	int i, down = 0;
	for (i = len - 1; i >= 0; i--) {
		ret.a[i] = (a[i] + down * (MAXN + 1)) / b;
		down = a[i] + down * (MAXN + 1) - ret.a[i] * b;
	}
	ret.len = len;
	while (ret.a[ret.len - 1] == 0 && ret.len > 1)
		ret.len--;
	return ret;
}

#define N 202
BigNum fac[N]={1};
int i=0,t=1;
int m,n;
int main(){
	for(i=1;i<N;i++){
		fac[i] = fac[i-1]*i;
	}
	while(1){
		cin >> m>> n;
		if(m==0&&n==0){
			return 0;
		}
		cout << "Test #" << t++ << ":" << endl;
		if(m<n){
		
			cout << "0" << endl;
		}else{
			BigNum a = fac[m+n]*(m-n+1)/(m+1);
			cout << a << endl;
		}
	}
}

