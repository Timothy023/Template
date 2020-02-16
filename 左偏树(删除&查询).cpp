#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int maxn=100005;
int n,m;
int l[maxn],r[maxn],d[maxn],v[maxn],fa[maxn];
int find(int x)
{
	if (fa[x]!=x)
		fa[x]=find(fa[x]);
	return fa[x];
}
int merge(int x,int y)
{
	if (!y)return x;
	if (!x)return y;
	if (v[x]<v[y])swap(x,y);
	r[x]=merge(r[x],y);
	if (d[l[x]]<d[r[x]])swap(l[x],r[x]);
	d[x]=d[r[x]]+1;
	return x;
}
int main ()
{
	while(scanf("%d",&n)!=EOF)
	{
		for (int b=1;b<=n;++b)
		{
			scanf ("%d",&v[b]);
			fa[b]=b;
			d[b]=l[b]=r[b]=0;
		}
		d[0]=-1;
		scanf ("%d",&m);
		for (int b=1;b<=m;++b)
		{
			int x,y;
			scanf ("%d%d",&x,&y);
			int p=find(x),q=find(y);
			if (p==q)puts("-1");
			else
			{
				int e=p,f=q,t1,t2,t,u,vv;
				v[e]/=2;fa[e]=e;u=l[e];vv=r[e];l[e]=0;r[e]=0;
				t1=merge(u,vv);fa[u]=fa[vv]=t1;
				u=t1;vv=e;t1=merge(u,vv);fa[u]=fa[vv]=t1;
				
				v[f]/=2;fa[f]=f;u=l[f],vv=r[f];l[f]=0;r[f]=0;
				t2=merge(u,vv);fa[u]=fa[vv]=t2;
				u=t2;vv=f;t2=merge(u,vv);fa[u]=fa[vv]=t2;
				
				t=merge(t1,t2);fa[t1]=fa[t2]=t;
				
				printf ("%d\n",v[t]);
			}
		}
	}
	return 0;
}
