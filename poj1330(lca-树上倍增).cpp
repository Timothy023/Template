#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cstdio>
#define maxn 15
using namespace std;
int n,step;
int tree[10005][105],deep[10005],fa[10005][maxn],root;
void dfs(int ro)
{
    for (int b=1;b<=tree[ro][0];++b)
    {
        deep[tree[ro][b]]=deep[ro]+1;
        dfs(tree[ro][b]);
    }
}
int main ()
{
    scanf ("%d",&step);
    while (step--)
    {
        scanf ("%d",&n);
        root=0;
        memset(tree,0,sizeof(tree));
        memset(deep,0,sizeof(deep));
        memset(fa,0,sizeof(fa));
        for (int b=1;b<n;++b)
        {
            int i,j;
            scanf ("%d%d",&i,&j);
            tree[i][++tree[i][0]]=j;
            fa[j][0]=i;
        }
        for (int b=1;b<=n;++b)if (!fa[b][0])root=b;
        deep[root]=1;
        dfs(root);
        for (int j=1;j<maxn;++j)
            for (int i=1;i<=n;++i)
                fa[i][j]=fa[fa[i][j-1]][j-1];
        int i,j;
        scanf ("%d%d",&i,&j);
        if (deep[i]<deep[j]){int t=i;i=j;j=t;}
        int D=deep[i]-deep[j];
        for (int b=0;b<maxn;++b)
            if ((1<<b) & D)
                i=fa[i][b];
        if (i==j)printf ("%d\n",i);
        else
        {
            for (int b=maxn-1;b>=0;--b)
                if (fa[i][b]!=fa[j][b])
                {
                    i=fa[i][b];
                    j=fa[j][b];
                }
            printf ("%d\n",fa[i][0]);
        }
    }
    return 0;
}
