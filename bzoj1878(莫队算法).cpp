#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define sq sqrt(n)
using namespace std;
int n,a[50005],m,sum[1000005];
struct node{int l,r,ans,xh;}q[200005];
bool cmp(node i,node j)
{
    if ((int)((i.l-1)/sq+1)==(int)((j.l-1)/sq+1))return i.r<j.r;
    else return i.l<j.l;
}
bool cmp1(node i,node j){return i.xh<j.xh;}
int main ()
{
    scanf ("%d",&n);
    for (int b=1;b<=n;++b)scanf ("%d",&a[b]);
    scanf ("%d",&m);
    for (int b=1;b<=m;++b){scanf ("%d%d",&q[b].l,&q[b].r);q[b].xh=b;}
    sort(q+1,q+m+1,cmp);
    for (int b=q[1].l;b<=q[1].r;++b)
    {
        if (sum[a[b]]==0)q[1].ans++;
        sum[a[b]]++;
    }
    for (int b=2;b<=m;++b)
    {
        q[b].ans=q[b-1].ans;
        if (q[b].l<q[b-1].l)
            for (int c=q[b-1].l-1;c>=q[b].l;--c)
            {
                if (sum[a[c]]==0)q[b].ans++;
                sum[a[c]]++;
            }
        else
            for (int c=q[b-1].l;c<=q[b].l-1;++c)
            {
                if (sum[a[c]]==1)q[b].ans--;
                sum[a[c]]--;
            }
        if (q[b].r<q[b-1].r)
            for (int c=q[b-1].r;c>=q[b].r+1;--c)
            {
                if (sum[a[c]]==1)q[b].ans--;
                sum[a[c]]--;
            }
        else
            for (int c=q[b-1].r+1;c<=q[b].r;++c)
            {
                if (sum[a[c]]==0)q[b].ans++;
                sum[a[c]]++;
            }
    }
    sort(q+1,q+m+1,cmp1);
    for (int b=1;b<=m;++b)printf ("%d\n",q[b].ans);
    return 0;
}
/*
6
1 2 3 4 3 5
3
1 2 
3 5
2 6
*/



