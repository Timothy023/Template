#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int step,n,m;
int first[200005],next[400005],i[400005],j[400005],k[400005],dis[200005];
bool flag,vis[200005];
void spfa(int ro)
{
	vis[ro]=1;
	for (int u=first[ro];u;u=next[u])
	{
		if (dis[j[u]]>dis[ro]+k[u])
		{
			if (vis[j[u]] || flag)
			{
				flag=1;
				break;
			}
			dis[j[u]]=dis[ro]+k[u];
			spfa(j[u]);
		}
	}
	vis[ro]=0;
}
int main ()
{
	scanf ("%d",&step);
	while (step-->0)
	{
		scanf ("%d%d",&n,&m);
		flag=false;
		for (int b=1;b<=n;++b)
		{
			first[b]=0;
			dis[b]=0;
			vis[b]=0;
		}
		for (int b=1;b<=m;++b)
		{
			scanf ("%d%d%d",&i[b],&j[b],&k[b]);
			next[b]=first[i[b]];first[i[b]]=b;
			if (k[b]>=0)
			{
				i[b+m]=j[b];j[b+m]=i[b];k[b+m]=k[b];
				next[b+m]=first[i[b+m]];first[i[b+m]]=b+m;
			}
		}
		for (int b=1;b<=n;++b)
		{
			spfa(b);
			if (flag)break;
		}
		printf (flag?"YE5\n":"N0\n");
	}
	return 0;
}
