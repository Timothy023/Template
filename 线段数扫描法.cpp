#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
const int N=40005;
long long ans;
int dui[N],n,sum[N<<3],col[N<<3],hash[N<<1];
struct node{int x1,x2,y,val;}wz[N<<1];
bool cmp(node i,node j){return i.y<j.y;}
void pushup(int l,int r,int rt)
{
    if (col[rt])sum[rt]=hash[r+1]-hash[l];
    else if (l==r)sum[rt]=0;
    else sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void update(int l,int r,int rt,int L,int R,int flag)
{
    if (L<=l && r<=R)
    {
        col[rt]+=flag;
        pushup(l,r,rt);
        return;
    }
    int mid=(l+r)>>1;
    if (L<=mid)update(lson,L,R,flag);
    if (mid<R)update(rson,L,R,flag);
    pushup(l,r,rt);
}
int main ()
{
    scanf ("%d",&n);
    for (int i=1;i<=n;++i)
    {
        int q,w,e;
        scanf ("%d%d%d",&q,&w,&e);
        wz[i*2-1].x1=wz[i*2].x1=q;
        wz[i*2-1].x2=wz[i*2].x2=w;
        wz[i*2-1].y=0;wz[i*2].y=e;
        wz[i*2-1].val=1;wz[i*2].val=-1;
        hash[i*2-1]=q;hash[i*2]=w;
    }
    n<<=1;
    sort(wz+1,wz+n+1,cmp);
    sort(hash+1,hash+n+1);
    for (int i=1;i<n;++i)
    {
        int l=lower_bound(hash+1,hash+n+1,wz[i].x1)-hash;
        int r=lower_bound(hash+1,hash+n+1,wz[i].x2)-hash-1;
        update(1,n,1,l,r,wz[i].val);
        ans+=(long long)sum[1]*(wz[i+1].y-wz[i].y);
    }
    printf ("%lld",ans);
    return 0;
}
