#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int step,n,tree[10005][105],f[10005],ans[10005],pre[10005],st,en; 
bool vis[10005];
int fa(int x)
{
    if (f[x]!=x)f[x]=fa(f[x]);
    return f[x];
}
void dfs(int ro)
{
    ans[ro]=ro;
    for (int b=1;b<=tree[ro][0];++b)
    {
        dfs(tree[ro][b]);
        int t1=fa(ro),t2=fa(tree[ro][b]);
        if (t1!=t2)f[t2]=t1;
    }
    vis[ro]=1;
    if (ro==st)
        if (vis[en])
        {
            printf("%d\n",ans[fa(en)]);
            return;
        }
    if (ro==en)
        if (vis[st])
        {
            printf("%d\n",ans[fa(st)]);
            return;
        }
}
int main ()
{
    scanf ("%d",&step);
    while (step--)
    {
        scanf ("%d",&n);
        for (int b=1;b<=n;++b)
        {
            f[b]=b;
            tree[b][0]=0;
            pre[b]=-1;
            ans[b]=0;
            vis[b]=0;
        }
        for (int b=1;b<n;++b)
        {
            int i,j;
            scanf ("%d%d",&i,&j);
            tree[i][++tree[i][0]]=j;
            pre[j]=i;
        }
        scanf ("%d%d",&st,&en);
        for (int b=1;b<=n;++b)
            if (pre[b]==-1)
            {
                dfs(b);
                break;
            }
    }
    return 0;
}
/*
1
10
1 2
1 3
3 4
4 5
4 6
6 7
6 8
3 9
3 10
5 10
*/
