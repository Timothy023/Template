#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<bitset>
using namespace std;
string s;
bitset <1100> sum[2200],t;
int n,m,ans,an[1100];
int main ()
{
    scanf ("%d%d",&n,&m);
    for (int b=1;b<=m;++b)
    {
        int i;
        cin >>s;
        for (int c=0;c<n;++c)
            sum[b][c+1]=s[c]-'0';
        scanf ("%d",&i);
        sum[b][n+1]=i;
    }
    for (int b=1;b<=n;++b)
    {
        bool flag=false;
        for (int c=b;c<=m;++c)
            if (sum[c][b])
            {
                t=sum[b];
                sum[b]=sum[c];
                sum[c]=t;
                flag=true;
                ans=max(ans,c);
                break;
            }
        if (!flag){puts("Cannot Determine");return 0;}
        for (int c=1;c<=m;++c)if (c!=b && sum[c][b])sum[c]^=sum[b];
    }
    printf ("%d\n",ans);
    for (int b=1;b<=n;++b)
        if (sum[b][n+1])puts("?y7M#");
        else puts("Earth");
    return 0;
}
/*
3 5 
011 1 
110 1 
101 0 
111 1 
010 1
*/





