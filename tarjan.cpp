#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int root;
int n,m,i,j[200005];
int first[100005],next[200005];
bool flag[100005],vis[100005];
int ti[100005],low[100005],step;
void tarjan(int ro)
{
    int sum=0;
    ti[ro]=++step;
    low[ro]=step;
    vis[ro]=1;
    for (int u=first[ro];u;u=next[u])
    {
        if (!vis[j[u]])
        {
            tarjan(j[u]);
            sum++;
            low[ro]=min(low[ro],low[j[u]]);
            if (ro!=root && low[j[u]]>=ti[ro])flag[ro]=1;
            if (ro==root && sum>=2)flag[ro]=1;
        }
        else low[ro]=min(low[ro],ti[j[u]]);
    }
}
int main ()
{
    scanf ("%d%d",&n,&m);
    for (int b=1;b<=m;++b)
    {
        scanf ("%d%d",&i,&j[b]);
        next[b]=first[i];first[i]=b;
        j[b+m]=i;
        next[b+m]=first[j[b]];first[j[b]]=b+m;
    }
    for (int b=1;b<=n;++b)
        if (!vis[b])
        {
            root=b;
            tarjan(b);
        }
    int ans=0;
    for (int b=1;b<=n;++b)
        if (flag[b])
            ans++;
    printf ("%d\n",ans);
    for (int b=1;b<=n;++b)
        if (flag[b])
            printf ("%d ",b);
    return 0;
}
