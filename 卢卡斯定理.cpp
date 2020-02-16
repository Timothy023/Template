#include<iostream>
#include<cstdlib>
#include<cstdio>
#define int long long
using namespace std;
int T,n,m,p,a[100005];
inline int ksm(int i,int j){
	int s=1;
	while (j){
		if (j & 1)
			s=(s*i)%p;
		i=(i*i)%p;
		j>>=1;
	}
	return s;
}
inline int C(int i,int j){
	if (i<j)return 0;
	return ((a[i]*ksm(a[j],p-2))%p*ksm(a[i-j],p-2))%p;
}
inline int lucas(int i,int j){
	if (!j)return 1;
	return C(i%p,j%p)*lucas(i/p,j/p)%p;
}
main (){
	scanf ("%lld",&T);
	while (T--){
		scanf ("%lld%lld%lld",&n,&m,&p);
		a[0]=1;for (int i=1;i<=p;++i)a[i]=(a[i-1]*i)%p;
		printf ("%lld\n",lucas(n+m,n));
	}
	return 0;
}
