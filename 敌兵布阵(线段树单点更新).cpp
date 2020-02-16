#include<iostream>
#include<cstdlib>
#include<cstdio>
#define maxn 50005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int asdf,n,i,j,sum[maxn<<2];
void push(int wz)
{
	sum[wz]=sum[wz<<1]+sum[wz<<1|1];
}
void build (int l,int r,int rt)
{
	if (l==r)
	{
		scanf ("%d",&sum[rt]);
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	push(rt);
}
int query(int l,int r,int rt)
{
	if (i<=l && r<=j)return sum[rt];
	int ans=0,m=(l+r)>>1;
	if (i<=m)ans+=query(lson);
	if (j>m)ans+=query(rson);
	return ans;
}
void add(int l,int r,int rt)
{
	if (l==r)
	{
		sum[rt]+=j;
		return;
	}
	int m=(l+r)>>1;
	if (i<=m)add(lson);
	else add(rson);
	push(rt);
}
int main ()
{
	scanf ("%d",&asdf);
	for (int step=1;step<=asdf;++step)
	{
		printf ("Case %d:\n",step);
		scanf ("%d",&n);
		build(1,n,1);
		char s[10];
		while (scanf ("%s",s) && s[0]!='E')
		{
			scanf ("%d%d",&i,&j);
			if (s[0]=='Q')
				printf ("%d\n",query(1,n,1));
			else
			{
				if (s[0]=='S')j=(-1)*j;
				add(1,n,1);
			}
		}
	}
	return 0;
}
