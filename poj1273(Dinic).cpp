#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int n,m,i[405],j[405],k[405],sum,first[405],next[1050],d[405],step,ans;
bool bfs()
{
	memset(d,-1,sizeof(d));
	int que[405],tot=1,tow=1;
	que[1]=1;d[1]=0;
	while (tot<=tow)
	{
		for (int u=first[que[tot]];u!=-1;u=next[u])
			if (d[j[u]]==-1 && k[u]>0)
			{
				d[j[u]]=d[que[tot]]+1;
				que[++tow]=j[u];
			}
		tot++;
	}
	if (d[m]==-1)return false;
	else return true;
}
int dinic(int ro,int flow)
{
	if (ro==m)return flow;
	for (int u=first[ro];u!=-1;u=next[u])
		if (d[j[u]]==d[ro]+1 && k[u]>0)
		{
			int flag=dinic(j[u],min(flow,k[u]));
			if (flag)
			{
				k[u]-=flag;
				k[u^1]+=flag;
				return flag;
			}
		}
	return 0;
}
int main ()
{
 	while (scanf ("%d%d",&n,&m)!=EOF)
 	{
		step=2;ans=0;
		memset(first,-1,sizeof(first));
		memset(next,-1,sizeof(next));
		for (int b=1;b<=n;++b)
		{
			scanf ("%d%d%d",&i[step],&j[step],&k[step]);
			next[step]=first[i[step]];first[i[step]]=step;
			step++;
			j[step]=i[step-1];i[step]=j[step-1];k[step]=0;
			next[step]=first[i[step]];first[i[step]]=step;
			step++;
		}
		while (bfs())ans+=dinic(1,2147483647);
		printf ("%d\n",ans);
	}
 	return 0;
}
