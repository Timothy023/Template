#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int fi[5005],ne[100005],i[100005],j[100005],k[100005],c[100005];
int n,m,s,t,step=1;
int que[500005],tot,tow,dis[5005],ans1,ans2;
int fa[5005],bian[5005];
bool flag[5005];
bool spfa()
{
	memset(dis,65,sizeof(dis));
	que[1]=s;tot=tow=1;dis[s]=0;
	while (tot<=tow)
	{
		flag[que[tot]]=false;
		for (int u=fi[que[tot]];u;u=ne[u])
		{
			if (dis[j[u]]>dis[que[tot]]+c[u] && k[u]>0)
			{
				dis[j[u]]=dis[que[tot]]+c[u];
				fa[j[u]]=que[tot];
				bian[j[u]]=u;
				if (!flag[j[u]])
				{
					flag[j[u]]=1;
					que[++tow]=j[u];
				}
			}
		}
		++tot;
	}
	if (dis[t]==dis[0])return false;
	else return true;
}
int main ()
{
	scanf ("%d%d%d%d",&n,&m,&s,&t);
	for (int b=1;b<=m;++b)
	{
		step++;
		scanf ("%d%d%d%d",&i[step],&j[step],&k[step],&c[step]);
		ne[step]=fi[i[step]];fi[i[step]]=step;
		step++;
		i[step]=j[step-1];j[step]=i[step-1];
		k[step]=0;c[step]=-c[step-1];
		ne[step]=fi[i[step]];fi[i[step]]=step;
	}
	while (spfa())
	{
		int mi=2147483647;
		for (int tmp=t;tmp!=s;tmp=fa[tmp])
			mi=min(mi,k[bian[tmp]]);
		for (int tmp=t;tmp!=s;tmp=fa[tmp])
		{
			k[bian[tmp]]-=mi;
			k[bian[tmp]^1]+=mi;
			ans1+=mi*c[bian[tmp]];
		}
		ans2+=mi;
	}
	printf ("%d %d",ans2,ans1);
	return 0;
}
