#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
struct node{int l,r,num,sum,ran,son;}tree[100005];
int n,k,i,root,sz,wz;
inline void rt(int &t)
{
	int k=tree[t].l;
	tree[t].l=tree[k].r;
	tree[k].r=t;
	tree[t].son=tree[tree[t].r].son+tree[tree[t].l].son+tree[t].sum;
	tree[k].son=tree[tree[k].r].son+tree[tree[k].l].son+tree[k].sum;
	t=k;
}
inline void lt(int &t)
{
	int k=tree[t].r;
	tree[t].r=tree[k].l;
	tree[k].l=t;
	tree[t].son=tree[tree[t].r].son+tree[tree[t].l].son+tree[t].sum;
	tree[k].son=tree[tree[k].r].son+tree[tree[k].l].son+tree[k].sum;
	t=k;
}
void update(int &ro,int x)
{
	if (!ro)
	{
		ro=++sz;
		tree[sz].num=x;
		tree[sz].sum=1;
		tree[sz].ran=rand();
		tree[sz].son=1;
		tree[sz].l=0;
		tree[sz].r=0;
		return;
	}
	if (tree[ro].num==x)
	{
		tree[ro].sum++;
		tree[ro].son++;
	}
	else if (tree[ro].num<x)
	{
		update(tree[ro].r,x);
		tree[ro].son++;
		if (tree[tree[ro].r].ran<tree[ro].ran)lt(ro);
	}
	else
	{
		update(tree[ro].l,x);
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
		if (tree[tree[ro].l].ran<tree[tree[ro].r].ran){rt(ro);del(tree[ro].r,x);}
		else {lt(ro);del(tree[ro].l,x);}
	}
	else if (tree[ro].num<x)del(tree[ro].r,x);
	else del(tree[ro].l,x);
	tree[ro].son--;
}
int q1(int ro,int x)
{
	if (tree[ro].num==x)return tree[tree[ro].l].son+1;
	else if (tree[ro].num<x)return tree[tree[ro].l].son+tree[ro].sum+q1(tree[ro].r,x);
	else return q1(tree[ro].l,x);
}
int q2(int ro,int x)
{
	if (!ro)return 0;
	if (tree[tree[ro].l].son<x && tree[tree[ro].l].son+tree[ro].sum>=x)
		return tree[ro].num;
	else if (tree[tree[ro].l].son<x)
		return q2(tree[ro].r,x-(tree[tree[ro].l].son+tree[ro].sum));
	else return q2(tree[ro].l,x);
}
void q3(int ro,int x)
{
	if (!ro)return;
	if (tree[ro].num<x && wz<tree[ro].num)wz=tree[ro].num;
	if (tree[ro].num<x)q3(tree[ro].r,x);
	else q3(tree[ro].l,x);
}
void q4(int ro,int x)
{
	if (!ro)return;
	if (tree[ro].num>x && wz>tree[ro].num)wz=tree[ro].num;
	if (tree[ro].num<=x)q4(tree[ro].r,x);
	else q4(tree[ro].l,x);
}
int main ()
{
	srand(time(0));
	scanf ("%d",&n);
	for (int b=1;b<=n;++b)
	{
		scanf ("%d%d",&k,&i);
		if (k==1)update(root,i);
		else if (k==2)del(root,i);
		else if (k==3)printf ("%d\n",q1(root,i));
		else if (k==4)printf ("%d\n",q2(root,i));
		else if (k==5)
		{
			wz=0;
			q3(root,i);
			printf ("%d\n",wz);
		}
		else if (k==6)
		{
			wz=2147483647;
			q4(root,i);
			printf ("%d\n",wz);
		}
	}
	return 0;
}
