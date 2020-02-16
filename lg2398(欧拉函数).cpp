#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int phi[2000005],f[2000005],n,m[2000005],p[2000005],sum;
long long ans;
int main ()
{
    scanf ("%d",&n);
    phi[1]=1;
    for (int i=2;i<=n;++i)
    {
        if (!m[i]){p[++sum]=m[i]=i;phi[i]=i-1;}
        for (int j=1,k;j<=sum && (k=p[j]*i)<=n;++j)
        {
            m[k]=p[j];
            if (m[i]==p[j])
            {
                phi[k]=phi[i]*p[j];
                break;
            }
            else phi[k]=phi[i]*(p[j]-1);
        }
    }
    for(int b=1;b<=n;++b) 
        for (int c=2;c<=n && b*c<=n;++c)
            f[b*c]+=phi[c]*b;
    for (int b=1;b<=n;++b)ans+=f[b];
    printf ("%lld",ans);
    return 0;
}

