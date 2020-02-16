#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int n,m,sor[600005],len;
struct node{int num,x;}a[300005],b[300005];
int wz[600005];
int ans[600005],sum;
int ef(int key)
{
	int l=1,r=sum;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (ans[mid]<=key && key<ans[mid+1])return mid+1;
		else if (ans[mid]<=key)l=mid+1;
		else r=mid-1;
	}
	return 1;
}
int main ()
{
	memset(wz,-1,sizeof(wz));
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=n;++i){scanf ("%d",&a[i].num);sor[++len]=a[i].num;}
	for (int i=1;i<=m;++i){scanf ("%d",&b[i].num);sor[++len]=b[i].num;}
	sort(sor+1,sor+len+1);
	for (int i=1;i<=n;++i)
		wz[upper_bound(sor+1,sor+len+1,a[i].num)-sor-1]=i;
	for (int i=1;i<=m;++i)
	{
		int u=upper_bound(sor+1,sor+len+1,b[i].num)-sor-1;
		if (wz[u]==-1)continue;
		int c;
		if (ans[sum]<wz[u])c=++sum;
		else c=ef(wz[u]);
		ans[c]=wz[u];
	}
	printf ("%d",sum);
	return 0;
}
