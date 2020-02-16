#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#define lson l,mid,ro<<1
#define rson mid+1,r,ro<<1|1
using namespace std;
int n,m,first[30005],next[60005],j[60005],val[30005];
int fa[30005],deep[30005],son[30005],top[30005],num[30005],dfn[30005],pos,trn[30005];
int sum[30005<<2],maxn[30005<<2];
void dfs1(int ro,int pre,int de)
{
	deep[ro]=de;
	fa[ro]=pre;
	num[ro]=1;
	for (int u=first[ro];u!=-1;u=next[u])
	{
		if (!num[j[u]])
		{
			dfs1(j[u],ro,de+1);
			num[ro]+=num[j[u]];
			if (son[ro]==-1 || num[j[u]]>num[son[ro]])
				son[ro]=j[u];
		}
	}
}
void dfs2(int ro,int t)
{
	top[ro]=t;
	dfn[ro]=++pos;
	trn[dfn[ro]]=ro;
	if (son[ro]==-1)return;
	dfs2(son[ro],t);
	for (int u=first[ro];u!=-1;u=next[u])
		if (j[u]!=son[ro] && j[u]!=fa[ro])dfs2(j[u],j[u]);
}
void build(int l,int r,int ro)
{
    if (l==r){sum[ro]=maxn[ro]=val[trn[l]];return;}
	int mid=(l+r)>>1;
	build(lson);build(rson);
	maxn[ro]=max(maxn[ro<<1],maxn[ro<<1|1]);
	sum[ro]=sum[ro<<1]+sum[ro<<1|1];
}
void update(int l,int r,int ro,int I,int J)
{
	if (l==r){sum[ro]=maxn[ro]=J;return;}
	int mid=(l+r)>>1;
	if (I<=mid)update(lson,I,J);
	else update(rson,I,J);
	maxn[ro]=max(maxn[ro<<1],maxn[ro<<1|1]);
	sum[ro]=sum[ro<<1]+sum[ro<<1|1];
}
int qmax(int l,int r,int ro,int L,int R)
{
	if (L<=l && r<=R)return maxn[ro];
	int mid=(l+r)>>1,s1=-2147483647;
	if (L<=mid)s1=qmax(lson,L,R);
	if (R>mid)s1=max(qmax(rson,L,R),s1);
	return s1;
}
void solvemax(int I,int J)
{
	int l=I,r=J,tmp=-2147483647;
	while (top[l]!=top[r])
	{
		if (deep[top[l]]>deep[top[r]])
		{
            tmp=max(tmp,qmax(1,pos,1,dfn[top[l]],dfn[l]));
            l=fa[top[l]];
        }
        else
        {
            tmp=max(tmp,qmax(1,pos,1,dfn[top[r]],dfn[r]));
            r=fa[top[r]];
        }
	}
	if (deep[l]>deep[r]){int t=l;l=r;r=t;}
	printf ("%d\n",max(tmp,qmax(1,pos,1,dfn[l],dfn[r])));
}
int qsum(int l,int r,int ro,int L,int R)
{
	if (L<=l && r<=R)return sum[ro];
	int mid=(l+r)>>1,s1=0;
	if (L<=mid)s1=qsum(lson,L,R);
	if (R>mid)s1+=qsum(rson,L,R);
	return s1;
}
void solvesum(int I,int J)
{
	int l=I,r=J,tmp=0;
	while (top[l]!=top[r])
	{
		if (deep[top[l]]>deep[top[r]])
		{
            tmp+=qsum(1,pos,1,dfn[top[l]],dfn[l]);
            l=fa[top[l]];
        }
        else
        {
            tmp+=qsum(1,pos,1,dfn[top[r]],dfn[r]);
            r=fa[top[r]];
        }
	}
	if (deep[l]>deep[r]){int t=l;l=r;r=t;}
	printf ("%d\n",tmp+qsum(1,pos,1,dfn[l],dfn[r]));
}
int main ()
{
	scanf ("%d",&n);
	for (int b=1;b<=n;++b)son[b]=first[b]=-1;
	for (int b=1;b<n;++b)
	{
        int i;       
		scanf ("%d%d",&i,&j[b]);
		next[b]=first[i];first[i]=b;
		j[n+b-1]=i;i=j[b];
		next[b+n-1]=first[i];first[i]=b+n-1;
	}
	for (int b=1;b<=n;++b)scanf ("%d",&val[b]);
	dfs1(1,0,1);
	dfs2(1,1);
	build(1,pos,1);
	scanf ("%d",&m);
	while (m--)
	{
		char st[8];int i1,i2;
		scanf ("%s%d%d",st,&i1,&i2);
		if (st[0]=='C')update(1,pos,1,dfn[i1],i2);
		else if (st[1]=='M')solvemax(i1,i2);
		else solvesum(i1,i2);
	}
	return 0;
}






