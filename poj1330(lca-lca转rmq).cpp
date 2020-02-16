#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n,Step;
int tree[10005][105],deep[50005],root,dg[50005],step,dp[50005][25],fa[10005],first[10005];
void dfs(int ro,int st)
{
    deep[++step]=st;
    dg[step]=ro;
    if (!first[ro])first[ro]=step;
    for (int b=1;b<=tree[ro][0];++b)
    {
        dfs(tree[ro][b],st+1);
        dg[++step]=ro;
        deep[step]=st;
    }
}
void rmq()
{
    for (int b=1;b<=step;++b)
        dp[b][0]=b;
    for (int j=1;j<20;++j)
        for (int i=1;i<=step;++i)
            if (i+(1<<j)-1<=step)
                dp[i][j]=deep[dp[i][j-1]]<deep[dp[i+(1<<(j-1))][j-1]]?dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
}
int main ()
{
    scanf ("%d",&Step);
    while (Step--)
    {
        scanf ("%d",&n);
        root=0;step=0;
        memset(tree,0,sizeof(tree));
        memset(fa,0,sizeof(fa));
        memset(first,0,sizeof(first));
        for (int b=1;b<n;++b)
        {
            int i,j;
            scanf ("%d%d",&i,&j);
            tree[i][++tree[i][0]]=j;
            fa[j]=i;
        }
        for (int b=1;b<=n;++b)if (!fa[b]){dfs(b,0);break;}
        int i,j;
        scanf ("%d%d",&i,&j);
        rmq();
        int l=first[i],r=first[j];
        if (l>r){int t=l;l=r;r=t;}
        int k=(int)(log(double(r-l+1))/log(2.0));
        printf ("%d\n",deep[dp[l][k]]<deep[dp[r-(1<<k)+1][k]]?dg[dp[l][k]]:dg[dp[r-(1<<k)+1][k]]);
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
9 10
5 10
*/




