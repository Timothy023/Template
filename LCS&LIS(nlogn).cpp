#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,u,a[100005];
int flag[100000];
int d[100005],len;
inline int ef(int key)
{
    int l=1,r=len;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (d[mid]<key && key<=d[mid+1])
            return mid+1;
        else if (key<d[mid])r=mid-1;
        else l=mid+1;
    }
    return 1;
}
inline void orzcy(int &s)
{
    s=0;int f=1;char ch=getchar();
    while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
    while (ch>='0' && ch<='9'){s=s*10+ch-'0';ch=getchar();}
}
inline void oyzcy(int key)
{
    if (key>=10)oyzcy(key/10);
    putchar(key%10+'0');
}
int main ()
{
    orzcy(n);
    for (int b=1;b<=n;++b)
    {
        orzcy(u);
        flag[u]=b;
    }
    for (int b=1;b<=n;++b)
    {
        orzcy(u);
        a[b]=flag[u];
    }
    d[++len]=a[1];
    for (int b=2;b<=n;++b)
    {
        int wz;
        if (!a[b])continue;
        if (d[len]<a[b])wz=++len;
        else wz=ef(a[b]);
        d[wz]=a[b];
    }
    oyzcy(len);
    return 0;
}
