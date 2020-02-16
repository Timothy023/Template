#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
struct node{int l,r,sum,son,num,ran;}tree[3000001];
int root[200001],n,m,a[200001],tmp,sz,ans;
inline void rt(int &t)
{
	int k=tree[t].l;
	tree[t].l=tree[k].r;
	tree[k].r=t;
	tree[t].son=tree[t].sum+tree[tree[t].r].son+tree[tree[t].l].son;
	tree[k].son=tree[k].sum+tree[tree[k].r].son+tree[tree[k].l].son;
	t=k;
}
inline void lt(int &t)
{
	int k=tree[t].r;
	tree[t].r=tree[k].l;
	tree[k].l=t;
	tree[t].son=tree[t].sum+tree[tree[t].r].son+tree[tree[t].l].son;
	tree[k].son=tree[k].sum+tree[tree[k].r].son+tree[tree[k].l].son;
	t=k;
}
void insert(int &ro,int x)
{
	if (!ro)
	{
		ro=++sz;
		tree[sz].num=x;
		tree[sz].son=1;
		tree[sz].sum=1;
		tree[sz].l=0;
		tree[sz].r=0;
		tree[sz].ran=rand();
		return;
	}
	if (tree[ro].num==x)
	{
		tree[ro].son++;
		tree[ro].sum++;
	}
	else if (tree[ro].num<x)
	{
		insert(tree[ro].r,x);
		tree[ro].son++;
		if (tree[tree[ro].r].ran<tree[ro].ran)lt(ro);
	}
	else
	{
		insert(tree[ro].l,x);
		tree[ro].son++;
		if (tree[tree[ro].l].ran<tree[ro].ran)rt(ro);
	}
}
void del(int &ro,int x)
{
	if (tree[ro].num==x)
	{
		if (tree[ro].sum>1)
		{
			tree[ro].sum--;
			tree[ro].son--;
			return;
		}
		if (tree[ro].l*tree[ro].r==0)
		{
			ro=tree[ro].l+tree[ro].r;
			return;
		}
		if (tree[tree[ro].l].ran<tree[tree[ro].r].ran)
		{
			rt(ro);
			del(tree[ro].r,x);
		}
		else
		{
			lt(ro);
			del(tree[ro].l,x);
		}
	}
	else if (tree[ro].num<x)del(tree[ro].r,x);
	else del(tree[ro].l,x);
	tree[ro].son--;
}
void build(int l,int r,int rt,int x,int num)
{
	insert(root[rt],num);
	if (l==r)return;
	int mid=(l+r)>>1;
	if (x<=mid)build(lson,x,num);
	else build(rson,x,num);
}
void change(int l,int r,int rt,int x,int y,int num)
{
	del(root[rt],num);
	insert(root[rt],y);
	if (l==r)return;
	int mid=(l+r)>>1;
	if (x<=mid)change(lson,x,y,num);
	else change(rson,x,y,num);
}
void ask_rank(int ro,int x)
{
	if (!ro)return;
	if (tree[ro].num==x){tmp+=tree[tree[ro].l].son;return;}
	if (tree[ro].num<x)
	{
		tmp+=tree[tree[ro].l].son+tree[ro].sum;
		ask_rank(tree[ro].r,x);
	}
	else ask_rank(tree[ro].l,x);
}
void get_rank(int l,int r,int rt,int x,int y,int num)
{
	if (x<=l && r<=y){ask_rank(root[rt],num);return;}
	int mid=(l+r)>>1;
	if (x<=mid)get_rank(lson,x,y,num);
	if (mid<y)get_rank(rson,x,y,num);
}
void ask_first(int ro,int x)
{
	if (!ro)return;
	if (tree[ro].num<x && tmp<tree[ro].num)tmp=tree[ro].num;
	if (tree[ro].num<x)ask_first(tree[ro].r,x);
	else ask_first(tree[ro].l,x);
}
void get_first(int l,int r,int rt,int x,int y,int num)
{
	if (x<=l && r<=y){ask_first(root[rt],num);return;}
	int mid=(l+r)>>1;
	if (x<=mid)get_first(lson,x,y,num);
	if (mid<y)get_first(rson,x,y,num);
}
void ask_last(int ro,int x)
{
	if (!ro)return;
	if (tree[ro].num>x && tmp>tree[ro].num)tmp=tree[ro].num;
	if (tree[ro].num<=x)ask_last(tree[ro].r,x);
	else ask_last(tree[ro].l,x);
}
void get_last(int l,int r,int rt,int x,int y,int num)
{
	if (x<=l && r<=y){ask_last(root[rt],num);return;}
	int mid=(l+r)>>1;
	if (x<=mid)get_last(lson,x,y,num);
	if (mid<y)get_last(rson,x,y,num);
}
int main ()
{
	srand(time(0));
	scanf ("%d%d",&n,&m);
	for (int b=1;b<=n;++b)scanf ("%d",&a[b]);
	for (int b=1;b<=n;++b)build(1,n,1,b,a[b]);
	for (int b=1;b<=m;++b)
	{
		int x,y,k,o;
		scanf ("%d",&o);
		if (o==1)
		{
			scanf ("%d%d%d",&x,&y,&k);
			tmp=1;
			get_rank(1,n,1,x,y,k);
			printf ("%d\n",tmp);
		}
		else if (o==2)
		{
			scanf ("%d%d%d",&x,&y,&k);
			int ll=0,rr=100000000;
			while (ll<=rr)
			{
				int mid=(ll+rr)>>1;
				tmp=1;get_rank(1,n,1,x,y,mid);
				if (tmp>k)rr=mid-1;
				else {ans=mid;ll=mid+1;}
			}
			printf ("%d\n",ans);
		}
		else if (o==3)
		{
			scanf ("%d%d",&x,&y);
			change(1,n,1,x,y,a[x]);
			a[x]=y;
		}
		else if (o==4)
		{
			scanf ("%d%d%d",&x,&y,&k);
			tmp=-2147483647;
			get_first(1,n,1,x,y,k);
			printf ("%d\n",tmp);
		}
		else if (o==5)
		{
			scanf ("%d%d%d",&x,&y,&k);
			tmp=2147483647;
			get_last(1,n,1,x,y,k);
			printf ("%d\n",tmp);
		}
	}
	return 0;
}
