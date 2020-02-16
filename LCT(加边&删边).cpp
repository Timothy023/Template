#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=300005;
int n,m;
int w[N],k,u,v;
int ch[N][2],fa[N],rev[N],su[N],que[N],tot;
inline bool isroot(int x){
	return (ch[fa[x]][0]!=x && ch[fa[x]][1]!=x);
}
inline void update(int x){
	int l=ch[x][0],r=ch[x][1];
	su[x]=w[x]^su[l]^su[r];
}
inline void pushdown(int x){
	int l=ch[x][0],r=ch[x][1];
	if (rev[x]){
		rev[x]^=1;rev[l]^=1;rev[r]^=1;
		swap(ch[x][0],ch[x][1]);
	}
}
inline void rotate(int x){
	int y=fa[x],z=fa[y],l,r;
	l=(ch[y][1]==x);r=l^1;
	if (!isroot(y))
		ch[z][ch[z][1]==y]=x;
	fa[ch[x][r]]=y;fa[y]=x;fa[x]=z;
	ch[y][l]=ch[x][r];ch[x][r]=y;
	update(y);update(x);
}
inline void splay(int x){
	que[++tot]=x;
	for (int i=x;!isroot(i);i=fa[i])
		que[++tot]=fa[i];
	while (tot)pushdown(que[tot--]);
	while (!isroot(x)){
		int y=fa[x],z=fa[y];
		if (!isroot(y))
			if ((ch[y][0]==x)^(ch[z][0]==y))rotate(x);
			else rotate(y);
		rotate(x);
	}
}
inline void access(int x){
	for (int t=0;x;t=x,x=fa[x]){
		splay(x);ch[x][1]=t;update(x);
	}
}
inline void makeroot(int x){
	access(x);splay(x);rev[x]^=1;
}
inline void link(int x,int y){
	makeroot(x);fa[x]=y;
}
inline void query(int x,int y){
	makeroot(x);access(y);splay(y);
}
inline int find(int x){
	access(x);splay(x);
	while (ch[x][0])x=ch[x][0];
	return x;
}
inline void cut(int x,int y){
	makeroot(x);access(y);splay(y);
	if (ch[y][0]==x)ch[y][0]=fa[x]=0;
}
int main (){
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf ("%d",&w[i]);
		su[i]=w[i];
	}
	for (int i=1;i<=m;++i){
		scanf ("%d%d%d",&k,&u,&v);
		if (k==0){
			query(u,v);printf ("%d\n",su[v]);
		}
		else if (k==1){
			if (find(u)!=find(v))link(u,v);
		}
		else if (k==2){
			if (find(u)==find(v))cut(u,v);
		}
		else {
			access(u);splay(u);w[u]=v;update(u);
		}
	}
	return 0;
}
