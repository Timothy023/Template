#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,m,sum,step;
int map[10005][505],num[10005],low[10005],st[10005],S;
bool vis[10005];
void dfs(int ro)
{
    int wz;
    st[++step]=ro;
    wz=step;
    low[ro]=num[ro]=++S;
    vis[ro]=1;
    for (int b=1;b<=map[ro][0];++b)
    {
        int ch=map[ro][b];
        if (!num[ch])
        {
            dfs(ch);
            low[ro]=min(low[ro],low[ch]);
        }
        else if (vis[ch])low[ro]=min(low[ro],num[ch]);
    }
    if (num[ro]==low[ro])
    {
        sum++;
        for (int b=wz;b<=step;++b)vis[st[b]]=0;
        step=wz-1;
    }
}
int main ()
{
    while (1)
    {
        scanf ("%d%d",&n,&m);
        if (!n && !m)break;
        for (int b=1;b<=n;++b)
            vis[b]=st[b]=num[b]=low[b]=map[b][0]=0;
        for (int b=1;b<=m;++b)
        {
            int i,j;
            scanf ("%d%d",&i,&j);
            map[i][++map[i][0]]=j;
        }
        S=step=sum=0;
        for (int b=1;b<=n;++b)
            if (!num[b])
                dfs(b);
        if (sum>1)puts("No");
        else puts("Yes");
    }
    return 0;
}
