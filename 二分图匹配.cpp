#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int n,m,e;
int p,q,step,ans;
int i[2000005],j[2000005];
int first[1000005],next[2000005];
bool vis[1000005];
int par[1000005];
bool dfs(int ro)
{
	if (vis[ro])return false;
	vis[ro]=1;
	for (int u=first[ro];u;u=next[u])
		if (par[j[u]]==-1 || dfs(par[j[u]]))
		{
			par[j[u]]=ro;
			return true;
		}
	return false;
}
int main ()
{
	scanf ("%d%d%d",&n,&m,&e);
	memset(par,-1,sizeof(par));
	for (int b=1;b<=e;++b)
	{
		scanf ("%d%d",&p,&q);
		if (p>n || q>m){b--;e--;continue;}
		i[++step]=p;j[step]=q+n;
		next[step]=first[i[step]];first[i[step]]=step;
	}
	for (int b=1;b<=n;++b)
	{
		memset(vis,0,sizeof(vis));
		if (dfs(b))
			ans++;
	}
	printf ("%d",ans);
	return 0;
}
