#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int i[30005],j[30005],k[30005];
int first[30005],next[30005];
int size[30005],vis[30005],maxn[30005];
int y[30005],d[30005];
int n,m,ans;
int getroot(int ro,int fa,int tmp)
{
	if (ro==0)return 0;
	size[ro]=1;
	maxn[ro]=0;
	int r1=0,r2=0;
	for (int u=first[ro];u!=-1;u=next[u])
	{
		if (j[u]==fa || vis[j[u]])continue;
		r2=getroot(j[u],ro,tmp);
		maxn[ro]=max(maxn[ro],size[j[u]]);
		if (r1==0 || maxn[r2]<maxn[r1])r1=r2;
		size[ro]+=size[j[u]];
	}
	maxn[ro]=max(maxn[ro],tmp-size[ro]);
	if (r1==0 || maxn[r1]>maxn[ro])r1=ro;
	return r1;
}
void getdeep(int ro,int fa)
{
	y[++y[0]]=d[ro];
	for (int u=first[ro];u!=-1;u=next[u])
	{
		if (j[u]==fa || vis[j[u]])continue;
		d[j[u]]=d[ro]+k[u];
		getdeep(j[u],ro);
	}
}
int cal(int ro,int init)
{
	int sum=0;
	y[0]=0;
	d[ro]=init;
	getdeep(ro,0);
	sort(y+1,y+y[0]+1);
	for (int l=1,r=y[0];l<=r;)
		if (y[l]+y[r]<=m){sum+=r-l;l++;}
		else r--;
	return sum;
}
void dfs(int ro,int tmp)
{
	ans+=cal(ro,0);
	vis[ro]=1;
	for (int u=first[ro];u!=-1;u=next[u])
	{
		if (vis[j[u]])continue;
		ans-=cal(j[u],k[u]);
		int tm=size[j[u]];
		if (tm>size[ro])tm=tmp-size[ro];
		dfs(getroot(j[u],0,tm),tm);
	}
}
int main ()
{
	while (1)
	{
		scanf ("%d%d",&n,&m);
		if (!n && !m)return 0;
		ans=0;
		for (int b=0;b<=n;++b){size[b]=vis[b]=0;first[b]=-1;}
		for (int b=1;b<n;++b)
		{
			scanf ("%d%d%d",&i[b],&j[b],&k[b]);
			next[b]=first[i[b]];first[i[b]]=b;
			i[b+n]=j[b];j[b+n]=i[b];k[b+n]=k[b];
			next[b+n]=first[j[b]];first[j[b]]=b+n;
		}
		dfs(getroot(1,0,n),n);
		printf ("%d\n",ans);
	}
	return 0;
}
