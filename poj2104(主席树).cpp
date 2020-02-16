#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,m,t[100005],a[100005],sz,tot;
int lson[3000005],rson[3000005],tree[3000005],sum[3000005];
int build(int l,int r)
{
    int root=++tot;
    sum[root]=0;
    if (l!=r)
    {
        int mid=(l+r)>>1;
        lson[root]=build(l,mid);
        rson[root]=build(mid+1,r);
    }
    return root;
}
int update(int root,int pos,int val)
{
    int nroot=++tot,tmp=nroot;
    int l=1,r=sz;
    sum[nroot]=sum[root]+val;
    while (l<r)
    {
        int mid=(l+r)>>1;
        if (pos<=mid)
        {
            lson[nroot]=++tot;rson[nroot]=rson[root];
            nroot=lson[nroot];root=lson[root];
            r=mid;
        }
        else
        {
            rson[nroot]=++tot;lson[nroot]=lson[root];
            nroot=rson[nroot];root=rson[root];
            l=mid+1;
        }
        sum[nroot]=sum[root]+val;
    }
    return tmp;
}
int query(int lroot,int rroot,int k)
{
    int l=1,r=sz;
    while (l<r)
    {
        int mid=(l+r)>>1;
        if (sum[lson[lroot]]-sum[lson[rroot]]>=k)
        {
            r=mid;
            lroot=lson[lroot];
            rroot=lson[rroot];
        }
        else
        {
            l=mid+1;
            k-=sum[lson[lroot]]-sum[lson[rroot]];
            lroot=rson[lroot];
            rroot=rson[rroot];
        }
    }
    return t[l];
}
int main ()
{
    scanf ("%d%d",&n,&m);
    for (int b=1;b<=n;++b)
    {
        scanf ("%d",&a[b]);
        t[b]=a[b];
    }
    sort(t+1,t+n+1);
    sz=unique(t+1,t+n+1)-t-1;
    tree[n+1]=build(1,sz);
    for (int b=n;b>=1;--b)
        tree[b]=update(tree[b+1],lower_bound(t+1,t+sz+1,a[b])-t,1);
    while (m--)
    {
        int i,j,k;
        scanf ("%d%d%d",&i,&j,&k);
        printf ("%d\n",query(tree[i],tree[j+1],k));
    }
    return 0;
}
