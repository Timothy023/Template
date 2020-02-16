#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=100005;
int ls[1800000],rs[1800000],sum[1800000];
int root[N],fa[N],rank[N],id[N];
int n,m,x,y,t1,t2,sz;
char ch;
int find(int x)
{
	if (fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
void update(int l,int r,int &rt,int val)
{
	if (!rt)rt=++sz;
	if (l==r)
	{
		sum[rt]=1;
		return;
	}
	int mid=(l+r)>>1;
	if (val<=mid)update(l,mid,ls[rt],val);
	else update(mid+1,r,rs[rt],val);
	sum[rt]=sum[ls[rt]]+sum[rs[rt]];
}
int query(int l,int r,int rt,int val)
{
	if (l==r)return l;
	int mid=(l+r)>>1;
	if (sum[ls[rt]]>=val)return query(l,mid,ls[rt],val);
	else return query(mid+1,r,rs[rt],val-sum[ls[rt]]);
}
int merge(int r1,int r2)
{
	if (!r1 || !r2)return r1+r2;
	ls[r1]=merge(ls[r1],ls[r2]);
	rs[r1]=merge(rs[r1],rs[r2]);
	sum[r1]=sum[ls[r1]]+sum[rs[r1]];
	return r1;
}
int main ()
{
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
	{
		scanf ("%d",&rank[i]);
		id[rank[i]]=i;
		fa[i]=i;
	}
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		t1=find(x),t2=find(y);
		fa[t2]=t1;
	}
	for (int i=1;i<=n;++i)
	{
		t1=find(i);
		update(1,n,root[t1],rank[i]);
	}
	scanf ("%d",&m);
	for (int i=1;i<=m;++i)
	{
		cin >>ch;scanf ("%d%d",&x,&y);
		if (ch=='Q')
		{
			t1=find(x);
			if (sum[root[t1]]<y)
			{
				puts("-1");
				continue;
			}
			printf ("%d\n",id[query(1,n,root[t1],y)]);
		}
		else
		{
			t1=find(x);
			t2=find(y);
			if (t1!=t2)
			{
				root[t1]=merge(root[t1],root[t2]);
				fa[t2]=t1;
			}
		}
	}
	return 0;
}
