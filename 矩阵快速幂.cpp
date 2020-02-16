#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n;
long long j;
const int Mod=1000000007;
struct node
{
    long long sum[105][105];
    friend node operator *(node g,node h)
    {
        node k;
        for (int b=1;b<=n;++b)
            for (int c=1;c<=n;++c)
            {
                k.sum[b][c]=0;
                for (int d=1;d<=n;++d)
                    k.sum[b][c]=(k.sum[b][c]+g.sum[b][d]*h.sum[d][c])%Mod;
            }
        return k;
    }
}i;
inline node ksm(long long mi)
{
    node s;
    for (int b=1;b<=n;++b)
            s.sum[b][b]=1;
    while (mi)
    {
        if (mi & 1)
            s=s*i;
        i=i*i;
        mi>>=1;
    }
    return s;
}
int main ()
{
    scanf ("%d",&n);cin >>j;
    for (int b=1;b<=n;++b)
        for (int c=1;c<=n;++c)
            scanf ("%d",&i.sum[b][c]);
    node u=ksm(j);
    for (int b=1;b<=n;++b)
    {
        for (int c=1;c<=n;++c)
            printf ("%d ",u.sum[b][c]);
        puts("");
    }
    return 0;
}
