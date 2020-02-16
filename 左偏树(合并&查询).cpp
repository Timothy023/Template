#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,m,fa[100005],l[100005],r[100005],d[100005],v[100005];
bool del[1000005];
int find(int x)
{
	if (fa[x]!=x)
		fa[x]=find(fa[x]);
	return fa[x];
}
int merge(int x,int y)
{
	if (!x)return y;
	if (!y)return x;
	if (v[x]>v[y] || (v[x]==v[y] && x>y))swap(x,y);
	r[x]=merge(r[x],y);
	if (d[l[x]]<d[r[x]])swap(l[x],r[x]);
	d[x]=d[r[x]]+1;
	return x;
}
int main ()
{
	scanf ("%d%d",&n,&m);
	for (int b=1;b<=n;++b){scanf ("%d",&v[b]);fa[b]=b;}
	for (int b=1;b<=m;++b)
	{
		int x,y,z;
		scanf ("%d",&x);
		if (x==1)
		{
			scanf ("%d%d",&y,&z);
			if (del[y] || del[z])continue;
			int p=find(y),q=find(z);
			if (p!=q)
			{
				int t=merge(p,q);
				fa[p]=fa[q]=t;
			}
		}
		else
		{
			scanf ("%d",&y);
			if (del[y])puts("-1");
			else
			{
				int p=find(y);del[p]=1;
				printf ("%d\n",v[p]);
				fa[p]=merge(l[p],r[p]);
				fa[fa[p]]=fa[p];
			}
		}
	}
	return 0;
}
