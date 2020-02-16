#include<iostream>
using namespace std;

int bb01(int c,int w)
{
    for(int i=v;i>=c;--i)
      f[i]=max(f[i],f[(i-c)]+w);
    return 0;
}

int bb02(int c,int w) 
{
    for(int i=c;i<=v;++i)
      f[i]=max(f[i],f[(i-c)]+w);
    return 0;
}

int bb03(int c,int w,int s) 
{
    if(c*s>=v) {bb02(c,w);return 0;}
    int k=1;
    while(k<s)
    {
      bb01(k*c,k*w);
      s-=k;
      k*=2;
    }
    bb01(s*c,s*w);
    return 0;
}

int bb04(int c,int w,int s)
{
    if(s==1) bb01(c,w);
    else if(s==0) bb02(c,w);
    else bb03(c,w,s);
    return 0;
}

int bb05(int c1,int c2,int w)
{
    for(int i=v;i>=c1;--i)
      for(int j=u;j>=c2;--j)
        f[i][j]=max(f[i][j],f[(i-c1)][(j-c2)]+w);
    return 0;
}

int bb06(int m)
{
    for(int i=v;i>=0;--i)
      for(int j=1;j<=m;++j)
        if(i>=c[j]) f[i]=max(f[i],f[(i-c[j])]+w[j]);
    return 0;
}
