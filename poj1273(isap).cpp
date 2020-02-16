#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cstdio>
using namespace std;
int i[405],j[405],k[405],first[405],Next[804],h[405],sh[405],n,m,step,ans,cur[405];
int min(int i1,int i2){return i1<i2?i1:i2;}
int isap(int ro,int flow)
{
    if (ro==m)return flow;
    int sum=0;
    for (int u=cur[ro];u!=-1;u=Next[u])
    {
        if (h[ro]>h[j[u]] && k[u]>0)
        {
            int flag=isap(j[u],min(flow-sum,k[u]));
            sum+=flag;
            k[u]-=flag;
            k[u^1]+=flag;
            cur[ro]=u;
            if (sum==flow)return sum;
        }
    }
    if (!(--sh[h[ro]]))h[ro]=m;
    sh[++h[ro]]++;
    return sum;
}
int main ()
{
    while (scanf ("%d%d",&n,&m)!=EOF)
    {
        step=2;ans=0;
        memset(first,-1,sizeof(first));
        memset(Next,-1,sizeof(Next));
        memset(h,0,sizeof(h));
        for (int b=1;b<=n;++b)
        {
            scanf ("%d%d%d",&i[step],&j[step],&k[step]);
            Next[step]=first[i[step]];first[i[step]]=step;
            step++;
            i[step]=j[step-1];j[step]=i[step-1];k[step]=0;
            Next[step]=first[i[step]];first[i[step]]=step;
            step++;
        }
        sh[0]=m;
        while (h[1]<m)
		{
        	for (int b=1;b<=m;++b)cur[b]=first[b];
        	ans+=isap(1,2147483647);
		}
        printf ("%d\n",ans);
    }
    return 0;
}
