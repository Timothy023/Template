#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,m,r,p;
int val[100005];
int first[100005],next[200005],i[200005],j[200005];
inline void orzcy(int &s)
{
	s=0;int f=1;char ch=getchar();
	while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){s=s*10+ch-'0';ch=getchar();}
	s*=f;
}
inline void oyzcy(int x)
{
	if (x>=10)oyzcy(x/10);
	putchar(x%10+'0');
}
int maxson[100005],sum[100005],fa[100005],deep[100005];
void dfs1(int ro)
{
	sum[ro]=1;
	for (int u=first[ro];u;u=next[u])
		if (!sum[j[u]])
		{
			deep[j[u]]=deep[ro]+1;
			fa[j[u]]=ro;
			dfs1(j[u]);
			sum[ro]+=sum[j[u]];
			maxson[ro]=sum[maxson[ro]]>sum[j[u]]?maxson[ro]:j[u];
		}
}
int top[100005],ldfn[100005],rdfn[100005],trn[100005],step;
void dfs2(int ro,int to)
{
	top[ro]=to;
	ldfn[ro]=++step;
	trn[step]=ro;
	if (maxson[ro])
		dfs2(maxson[ro],to);
	for (int u=first[ro];u;u=next[u])
		if (!ldfn[j[u]])
			dfs2(j[u],j[u]);
	rdfn[ro]=step;
}
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
int tree[100005<<2],col[100005<<2];
inline void pushdown (int l,int r,int rt,int mid)
{
	tree[rt<<1]=(tree[rt<<1]+(long long)(mid-l+1)*col[rt])%p;
	tree[rt<<1|1]=(tree[rt<<1|1]+(long long)(r-mid)*col[rt])%p;
	col[rt<<1]=((long long)col[rt<<1]+col[rt])%p;
	col[rt<<1|1]=((long long)col[rt<<1|1]+col[rt])%p;
	col[rt]=0;
}
void build(int l,int r,int rt)
{
	if (l==r)
	{
		tree[rt]=val[trn[l]]%p;
		return;
	}
	int mid=(l+r)>>1;
	build(lson);
	build(rson);
	tree[rt]=(tree[rt<<1]+tree[rt<<1|1])%p;
}
void update(int l,int r,int rt,int L,int R,int key)
{
	if (L<=l && r<=R)
	{
		tree[rt]=(tree[rt]+(long long)(r-l+1)*key)%p;
		col[rt]=((long long)col[rt]+key)%p;
		return;
	}
	int mid=(l+r)>>1;
	if (col[rt])pushdown(l,r,rt,mid);
	if (L<=mid)update(lson,L,R,key);
	if (mid<R)update(rson,L,R,key);
	tree[rt]=(tree[rt<<1]+tree[rt<<1|1])%p;
}
int query(int l,int r,int rt,int L,int R)
{
	if (L<=l && r<=R)return tree[rt];
	int mid=(l+r)>>1,S=0;
	if (col[rt])pushdown(l,r,rt,mid);
	if (L<=mid)S=((long long)S+query(lson,L,R))%p;
	if (mid<R)S=((long long)S+query(rson,L,R))%p;
	tree[rt]=(tree[rt<<1]+tree[rt<<1|1])%p;
	return S;
}
int main ()
{
	orzcy(n);orzcy(m);orzcy(r);orzcy(p);
	for (int b=1;b<=n;++b)
		orzcy(val[b]);
	for (int b=1;b<n;++b)
	{
        orzcy(i[b]);orzcy(j[b]);
        next[b]=first[i[b]];first[i[b]]=b;
        i[b+n]=j[b];j[b+n]=i[b];
        next[b+n]=first[i[b+n]];first[i[b+n]]=b+n;
	}
    dfs1(r);
    dfs2(r,r);
    build(1,n,1);
    for (int b=1;b<=m;++b)
    {
		int k;
		orzcy(k);
		if (k==1)
		{
			int x,y,z;
			orzcy(x);orzcy(y);orzcy(z);
			while (top[x]!=top[y])
				if (deep[top[x]]<deep[top[y]])
				{
					update(1,n,1,ldfn[top[y]],ldfn[y],z);
					y=fa[top[y]];
				}
				else
				{
					update(1,n,1,ldfn[top[x]],ldfn[x],z);
					x=fa[top[x]];
				}
			if (deep[x]<deep[y])update(1,n,1,ldfn[x],ldfn[y],z);
			else update(1,n,1,ldfn[y],ldfn[x],z);
		}
		else if (k==2)
		{
			int x,y,sum=0;
			orzcy(x);orzcy(y);
			while (top[x]!=top[y])
				if (deep[top[x]]<deep[top[y]])
				{
					sum=((long long)sum+query(1,n,1,ldfn[top[y]],ldfn[y]))%p;
					y=fa[top[y]];
				}
				else
				{
					sum=((long long)sum+query(1,n,1,ldfn[top[x]],ldfn[x]))%p;
					x=fa[top[x]];
				}
			if (deep[x]<deep[y])
				sum=((long long)sum+query(1,n,1,ldfn[x],ldfn[y]))%p;
			else
				sum=((long long)sum+query(1,n,1,ldfn[y],ldfn[x]))%p;
			printf ("%d\n",sum);
		}
		else if (k==3)
		{
			int x,z;
			orzcy(x);
			orzcy(z);
			update(1,n,1,ldfn[x],rdfn[x],z);
		}
		else
		{
			int x;
			orzcy(x);
			printf ("%d\n",query(1,n,1,ldfn[x],rdfn[x]));
		}
	}
	return 0;
}
