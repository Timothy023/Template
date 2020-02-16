#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
namespace rp_max{
	const int N=1000005;
	struct xie_dui{
		int n,val[N],fa[N],ls[N],rs[N];
		int get_fa(int x){
			return (fa[x]==x)?(x):(fa[x]=get_fa(fa[x]));
		}
		int merge(int x,int y){
			if (!x || !y)return x+y;
			if (val[x]>val[y])x^=y^=x^=y;
			rs[x]=merge(rs[x],y);
			ls[x]^=rs[x]^=ls[x]^=rs[x];
			return x;
		}
		void del(int x){
			fa[x]=merge(ls[x],rs[x]);
			fa[fa[x]]=fa[x];
		}
	}q;
	int m,x,y,t1,t2,tmp;
	bool vis[N];
	char ch[5];
	void solve(){
		scanf ("%d",&q.n);
		for (int i=1;i<=q.n;++i){
			scanf ("%d",&q.val[i]);
			q.fa[i]=i;
		}
		scanf ("%d",&m);
		for (int i=1;i<=m;++i){
			scanf ("%s",ch);
			if (ch[0]=='M'){
				scanf ("%d%d",&x,&y);
				if (vis[x] || vis[y])continue;
				t1=q.get_fa(x);
				t2=q.get_fa(y);
				if (t1!=t2){
					tmp=q.merge(t1,t2);
					if (tmp==t1)q.fa[t2]=t1;
					else q.fa[t1]=t2;
				}
			}
			else{
				scanf ("%d",&x);
				if (vis[x]){
					puts("0");
					continue;
				}
				t1=q.get_fa(x);
				printf ("%d\n",q.val[t1]);
				vis[t1]=1;
				q.del(t1);
			}
		}
	}
}
int main (){
	rp_max::solve();
	return 0;
}
