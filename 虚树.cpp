#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
namespace rp_max{
	const int N=250005;
	int n,m,x,y,z,cnt,a[N];
	int len,top,q[N];
	int fa[N][25],dep[N],dfn[N],clo;
	int fi[N],ne[N<<1],j[N<<1],k[N<<1],step;
	long long val[N];
	bool cmp(int i,int j){return dfn[i]<dfn[j];}
	void addedge(int fr,int to,int cost){
		if (fr==to)return;
		j[++step]=to;k[step]=cost;ne[step]=fi[fr];fi[fr]=step;
	}
	void dfs(int ro,int pre){
		dfn[ro]=++clo;fa[ro][0]=pre;dep[ro]=dep[pre]+1;
		for (int i=1;i<=20;++i)fa[ro][i]=fa[fa[ro][i-1]][i-1];
		for (int u=fi[ro];u;u=ne[u]){
			if (j[u]==pre)continue;
			val[j[u]]=min(val[ro],(long long)k[u]);
			dfs(j[u],ro);
		}
	}
	int get_lca(int x,int y){
		if (dep[x]<dep[y])x^=y^=x^=y;
		int D=dep[x]-dep[y];
		for (int j=20;~j;--j)
			if ((D&(1<<j)))x=fa[x][j];
		if (x==y)return x;
		for (int j=20;~j;--j)
			if (fa[x][j]!=fa[y][j]){
				x=fa[x][j];y=fa[y][j];
			}
		return fa[x][0];
	}
	long long dp(int ro){
		if (!fi[ro])return val[ro];
		long long sum=0;
		for (int u=fi[ro];u;u=ne[u])sum+=dp(j[u]);
		fi[ro]=0;
		return min(sum,val[ro]);
	}
	void work(){
		scanf ("%d",&cnt);len=1;step=0;
		for (int i=1;i<=cnt;++i)
			scanf ("%d",&a[i]);
		sort(a+1,a+cnt+1,cmp);
		for (int i=2;i<=cnt;++i)
			if (get_lca(a[len],a[i])!=a[len])a[++len]=a[i];
		q[top=1]=1;
		for (int i=1;i<=len;++i){
			int tmp=get_lca(a[i],q[top]);
			while (1){
				if (dep[q[top-1]]<=dep[tmp]){
					addedge(tmp,q[top--],0);
					if (q[top]!=tmp)q[++top]=tmp;
					break;
				}
				addedge(q[top-1],q[top],0);top--;
			}
			if (q[top]!=a[i])q[++top]=a[i];
		}
		for (;top>1;--top)addedge(q[top-1],q[top],0);
		printf ("%lld\n",dp(1));
	}
	void solve(){
		scanf ("%d",&n);
		for (int i=1;i<n;++i){
			scanf ("%d%d%d",&x,&y,&z);
			addedge(x,y,z);
			addedge(y,x,z);
		}
		val[1]=9e18;dfs(1,0);
		scanf ("%d",&m);
		memset(fi,0,sizeof(fi));
		while (m --> 0)work();
	}
}
int main (){
	rp_max::solve();
	return 0;
}
