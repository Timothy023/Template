#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,a[25],pos[25],t,x,y;
double avr,sum[25],T,pre,ans,mn=1e30;
inline void solve(){
	ans=0;
	memset(sum,0,sizeof(sum));
	for (int i=1;i<=n;++i)
		pos[i]=rand()%m+1;
	for (int i=1;i<=n;++i)
		sum[pos[i]]+=a[i];
	for (int i=1;i<=m;++i)
		ans+=(sum[i]-avr)*(sum[i]-avr);
	T=10000;
	while (T>0.1){
		T*=0.9;
		t=rand()%n+1;
		x=pos[t];
		if (T>500)y=min_element(sum+1,sum+m+1)-sum;
		else y=rand()%m+1;
		if (x==y)continue;
		pre=ans;
		ans-=(sum[x]-avr)*(sum[x]-avr);
		ans-=(sum[y]-avr)*(sum[y]-avr);
		sum[x]-=a[t];sum[y]+=a[t];
		ans+=(sum[x]-avr)*(sum[x]-avr);
		ans+=(sum[y]-avr)*(sum[y]-avr);
		if (rand()%10000>T && ans>pre){
			sum[x]+=a[t];sum[y]-=a[t];
			ans=pre;
		}
		else pos[t]=y;
	}
	if (ans<mn)mn=ans;
}
int main (){
	srand(19260817);
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf ("%d",&a[i]);
		avr+=a[i];
		swap(a[i],a[rand()%i+1]);
	}
	avr/=m;
	for (int i=1;i<=19260;++i)solve();
	printf ("%.2lf",sqrt(mn/m));
	return 0;
}
