#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define pf(x) x*x
using namespace std;
int n;
double a[105],sum[105][105];
int main ()
{
    scanf ("%d",&n);
    for (int b=1;b<=n;++b)scanf ("%lf",&a[b]);
    for (int b=1;b<=n;++b)
    {
        for (int c=1;c<=n;++c)
        {
            double t;
            scanf ("%lf",&t);
            sum[b][c]=2*(t-a[c]);
            sum[b][n+1]+=pf(t)-pf(a[c]);
        }
    }
    for (int b=1;b<=n;++b)
    {
        int wz=-1;
        for (int c=b;c<=n;++c)if(fabs(sum[c][b])>1e-6){wz=c;break;}
        if (wz==-1)continue;
        if (wz!=b)
            for (int c=1;c<=n+1;++c)
            {
                double t=sum[b][c];
                sum[b][c]=sum[wz][c];
                sum[wz][c]=t;
            }
        double tt=sum[b][b];
        for (int c=b;c<=n+1;++c)sum[b][c]/=tt;
        for (int c=1;c<=n;++c)
            if (c!=b)
            {
                double ttt=sum[c][b];
                for (int d=1;d<=n+1;++d)
                    sum[c][d]-=ttt*sum[b][d];
            }
                    
    }
    for (int b=1;b<n;++b)printf ("%.3lf ",sum[b][n+1]);
    printf ("%.3lf\n",sum[n][n+1]);
    return 0;
}
/*
2
0.0 0.0
-1.0 1.0
1.0 0.0
*/



