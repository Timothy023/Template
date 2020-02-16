#include<iostream>
#include<cstdio>
using namespace std;
struct kkk
{
	int i,j,k;
}que[101],t;
int n,m,f[101],sum,ans;
void kp(int l,int r)
{
	int x=que[(l+r)/2].k,i=l,j=r;
	while (i<=j)
	{
		while (que[i].k<x)i++;
		while (que[j].k>x)j--;
		if (i<=j){t=que[i];que[i++]=que[j];que[j--]=t;}
	}
	if (l<j)kp(l,j);
	if (i<r)kp(i,r);
}
int fa (int x){if (f[x]!=x)f[x]=fa(f[x]);return f[x];}
bool hb(int a1,int a2)
{
	int t1=fa(a1),t2=fa(a2);
	if (t1==t2)return false;
	f[t2]=t1;
	return true;
}
int main ()
{
	scanf ("%d%d",&n,&m);
	for (int b=1;b<=n;++b)scanf ("%d%d%d",&que[b].i,&que[b].j,&que[b].k);
	kp(1,n);for (int b=1;b<=n;++b)f[b]=b;
	for (int b=1;b<=m && sum<n;++b)if (hb(que[b].i,que[b].j)){++sum;ans+=que[b].k;}
	printf ("%d",ans);
	return 0;
}
