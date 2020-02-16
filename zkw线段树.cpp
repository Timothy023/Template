#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=100005;
int n,m,x,y,z,k;
struct tree
{
    int M,T;
    long long t[N<<2],ans,col[N<<2];
    long long len[N<<2];
    void init()
    {
        for (T=M=1;M<n+2;M<<=1,++T);
        for (int i=M;i<M+M;++i)len[i]=1;
        for (int i=M-1;i>=1;--i)
            len[i]=len[i<<1]<<1;
    }
    void up(int wz){for (wz>>=1;wz>1;wz>>=1)pushup(wz);}
    void dn(int wz){for (int i=T;i>=1;--i)pushdown(wz>>i);}
    void pushup(int wz){t[wz]=t[wz<<1]+t[wz<<1|1]+col[wz]*len[wz];}
    void pushdown(int wz)
    {
        col[wz<<1]+=col[wz];col[wz<<1|1]+=col[wz];
        t[wz<<1]+=col[wz]*len[wz<<1];t[wz<<1|1]+=col[wz]*len[wz<<1|1];
        col[wz]=0;
    }
    void add(int wz,long long val)
    {
        for (t[wz+=M]=val,wz>>=1;wz;wz>>=1)
            t[wz]=t[wz<<1]+t[wz<<1|1];
    }
    void query(int l,int r)
    {
        ans=0;l=l+M-1,r=r+M+1;
        dn(l);dn(r);
        for (;l^r^1;l>>=1,r>>=1)
        {
            if ((l&1)==0)ans+=t[l^1];
            if ((r&1)==1)ans+=t[r^1];
        }
        printf ("%lld\n",ans);
    }
    void update(int l,int r,int val)
    {
        int ss=l+M-1,tt=r+M+1;
        dn(ss+M-1);dn(tt);
        for (l=l+M-1,r=r+M+1;l^r^1;l>>=1,r>>=1)
        {
            if ((l&1)==0){col[l^1]+=val;t[l^1]+=val*len[l^1];}
            if ((r&1)==1){col[r^1]+=val;t[r^1]+=val*len[r^1];}
        }
        up(ss);up(tt);
    }
}zkw;
int main ()
{
    scanf ("%d%d",&n,&m);
    zkw.init();
    for (int i=1;i<=n;++i)
    {
        scanf ("%d",&x);
        zkw.add(i,x);
    }
    for (int i=1;i<=m;++i)
    {
        scanf ("%d",&k);
        if (k==1)
        {
            scanf ("%d%d%d",&x,&y,&z);
            zkw.update(x,y,z);
        }
        else
        {
            scanf ("%lld%lld",&x,&y);
            zkw.query(x,y);
        }
    }
    return 0;
}
