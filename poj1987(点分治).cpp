#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int i[80000],j[80000],w[80000],n,m,k,size[60000],maxn[60000];
int first[60000],next[120000],vis[60000],ans,d[60000],y[60000];
int read()
{
	char ch=getchar();
	int s=0,flag=1;
	while (ch<'0' || ch>'9'){if (ch=='-')flag=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*flag;
}
int getroot(int ro,int fa,int tmp)
{
    if (ro==0)return 0;
	size[ro]=1;
	maxn[ro]=0;
	int ret=0,ret2=0;
	for (int u=first[ro];u>0;u=next[u])
	{
		if (j[u]==fa || vis[j[u]])continue;
		ret2=getroot(j[u],ro,tmp);
		maxn[ro]=max(maxn[ro],size[j[u]]);
		if (ret==0 || maxn[ret2]<maxn[ret])ret=ret2;
		size[ro]+=size[j[u]];
	}
	maxn[ro]=max(maxn[ro],tmp-size[ro]);
	if (ret==0 || maxn[ret]>maxn[ro])ret=ro;
	return ret;
}
void getdeep(int ro,int fa)
{
	y[++y[0]]=d[ro];
	for (int u=first[ro];u!=-1;u=next[u])
	{
		if (j[u]==fa || vis[j[u]])continue;
		d[j[u]]=d[ro]+w[u];
		getdeep(j[u],ro);
	}
}
int cal(int ro,int init)
{int sum=0;
    y[0]=0;
	d[ro]=init;
	getdeep(ro,0);
	sort(y+1,y+y[0]+1);
	for (int l=1,r=y[0];l<=r;)
		if (y[l]+y[r]<=k){sum+=r-l;++l;}
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
		ans-=cal(j[u],w[u]);
		int tm=size[j[u]];
		if (tm>size[ro])tm=n-size[ro];
		dfs(getroot(j[u],0,tm),tm);
	}
}
int main ()
{
    n=read();m=read();
    for (int b=0;b<=n;++b){size[b]=vis[b]=0;first[b]=-1;}
    ans=0;
    for (int b=1;b<=m;++b)
    {
        i[b]=read();j[b]=read();w[b]=read();
       	next[b]=first[i[b]];first[i[b]]=b;
       	i[b+m]=j[b];j[b+m]=i[b];w[b+m]=w[b];
       	next[b+m]=first[i[b+m]];first[i[b+m]]=b+m;
    }
    k=read();
    for (int b=1;b<=n;++b)
       	if (!vis[b])
            dfs(getroot(1,0,n),n);
    printf ("%d\n",ans);
	return 0;
}
/*
7 6
1 6 13 E
6 3 9 E
3 5 7 S
4 1 3 N
2 4 20 W
4 7 2 S
10
*/
