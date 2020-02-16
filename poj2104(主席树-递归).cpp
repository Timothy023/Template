#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int sz,n,m,a[100005],t[100005],tot;
int tree[5000005],lson[5000005],rson[5000005],sum[5000005];
void update(int l,int r,int &nroot,int root,int pos,int val)
{
	
	nroot=++tot;
	if (l==r){sum[nroot]=val;return;}
	sum[nroot]=sum[root]+val;
	int mid=(l+r)>>1;
	if (pos<=mid)
	{
		update(l,mid,lson[nroot],lson[root],pos,val);
		rson[nroot]=rson[root];
	}
	else
	{
		update(mid+1,r,rson[nroot],rson[root],pos,val);
		lson[nroot]=lson[root];
	}
}
int query(int l,int r,int lroot,int rroot,int k)
{
	if (l==r)return t[l];
	int mid=(l+r)>>1;
	if (sum[lson[lroot]]-sum[lson[rroot]]>=k)
		return query(l,mid,lson[lroot],lson[rroot],k);
	else
		return query(mid+1,r,rson[lroot],rson[rroot],k-(sum[lson[lroot]]-sum[lson[rroot]]));
}
int main ()
{
 	scanf ("%d%d",&n,&m);
 	for (int b=1;b<=n;++b)
	{
		scanf("%d",&a[b]);
		t[b]=a[b];
	}
	sort(t+1,t+n+1);
	sz=unique(t+1,t+n+1)-t-1;
	for (int b=n;b>=1;--b)
		update(1,sz,tree[b],tree[b+1],lower_bound(t+1,t+n+1,a[b])-t,1);
	while (m--)
	{
		int i,j,k;
		scanf ("%d%d%d",&i,&j,&k);
		printf ("%d\n",query(1,sz,tree[i],tree[j+1],k));
	}
 	return 0;
}
