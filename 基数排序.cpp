#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int M=65537;
const int N=100005;
const int f=(1<<16)-1;
int s[M],a[N],b[N],n;
int I(){
	int s=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
void rsort(){
	for (int i=1;i<=n;++i)s[a[i]&f]++;
	for (int i=1;i<M;++i)s[i]+=s[i-1];
	for (int i=n;i>=1;--i)b[s[a[i]&f]--]=a[i];
	for (int i=0;i<M;++i)s[i]=0;
	for (int i=1;i<=n;++i)s[b[i]>>16]++;
	for (int i=1;i<M;++i)s[i]+=s[i-1];
	for (int i=n;i>=1;--i)a[s[b[i]>>16]--]=b[i];
}
int main (){
	register int i;
	for (n=I(),i=1;i<=n;++i)a[i]=I();
	for (rsort(),i=1;i<=n;++i)printf ("%d ",a[i]);
	return 0;
}
