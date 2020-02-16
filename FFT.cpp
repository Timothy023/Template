#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<complex>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
const double pi=acos(-1);
typedef complex<double> E;
char a[50001];
int le,len,L,R[50001],num[50001];
E i[50001],j[50001];
void fft(E *i,int f)
{
	for (int b=0;b<le;++b)if (b<R[b])swap(i[b],i[R[b]]);
	for (int b=1;b<le;b<<=1)
	{
		E wn(cos(pi/b),f*sin(pi/b));
		for (int p=b<<1,c=0;c<le;c+=p)
		{
			E w(1,0);
			for (int d=0;d<b;++d,w*=wn)
			{
				E x=i[c+d],y=w*i[b+c+d];
				i[c+d]=x+y;i[b+c+d]=x-y;
			}
		}
	}
}
int main ()
{
	scanf ("%s",a);le=strlen(a);len=le-1;
	for (int b=0;b<le;++b)i[b]=E(a[b]-'0',0);
	scanf ("%s",a);le=strlen(a);len+=le-1;
	for (int b=0;b<le;++b)j[b]=E(a[b]-'0',0);
	for (le=1;le<=len;le<<=1)L++;
	for (int b=0;b<le;++b)R[b]=(R[b>>1]>>1)|((b&1)<<(L-1));
	fft(i,1);fft(j,1);
	for (int b=0;b<=le;++b)i[b]*=j[b];
	fft(i,-1);
	for (int b=0;b<=len;++b)
	{
		num[b]+=(int)(i[len-b].real()/le+0.5);
		num[b+1]+=num[b]/10;
		num[b]%=10;
	}
	if (num[len+1])len++;
	while (num[len]>=10)
	{
		num[len+1]+=num[len]/10;
		num[len]%=10;
		len++;
	}
	while (!num[len] && len)len--;
	for (int b=len;b>=0;--b)
		printf ("%d",num[b]);
	return 0;
}
