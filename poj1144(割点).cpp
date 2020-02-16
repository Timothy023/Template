#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,tree[105][105],num[105],low[105],root,step,ans;
bool vis[105],flag[105];
void dfs(int ro)
{
    int child=0;
    vis[ro]=true;
    num[ro]=low[ro]=++step;
    for (int b=1;b<=tree[ro][0];++b)
    {
        int ch=tree[ro][b];
        if (!vis[ch])
        {
            child++;
            dfs(ch);
            low[ro]=min(low[ro],low[ch]);
            if (ro!=root && low[ch]>=num[ro])flag[ro]=true;
            if (ro==root && child>=2)flag[ro]=true;
        }
        else low[ro]=min(low[ro],num[ch]);
    }
}
int main ()
{
    while (scanf ("%d",&n) && n)
    {
        for (int b=1;b<=n;++b)
        {
            num[b]=0;
            low[b]=0;
            tree[b][0]=0;
            vis[b]=0;
            flag[b]=0;
        }
        int i,j;
        step=ans=0;root=1;
        while (scanf ("%d",&i) && i)
            while (getchar()!='\n')
            {
                scanf ("%d",&j);
                tree[i][++tree[i][0]]=j;
                tree[j][++tree[j][0]]=i;
            }
        dfs(root);
        for (int b=1;b<=n;++b)
            if (flag[b])
                ans++;
        printf ("%d\n",ans);
    }
    return 0;
}
/*
5
5 1 2 3 4
0
6
2 1 3
5 4 6 2
0
0
*/
