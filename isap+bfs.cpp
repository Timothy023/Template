#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=20005;
const int M=200005;
int n,m,st,en,x,y,z,f,ans;
int fi[N],ne[M],j[M],k[M],step=1;
int h[N],hs[N],cur[N];
int que[N],tot,tow;
char ch;
inline void orzcy(int &s){
	s=0;ch=getchar();f=1;
	while (ch<'0' || ch>'9'){
		if (ch=='-')f=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9'){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
}
inline void addedge(int fr,int to,int flow){
	j[++step]=to;k[step]=flow;ne[step]=fi[fr];fi[fr]=step;
	j[++step]=fr;k[step]=0;ne[step]=fi[to];fi[to]=step;
}
inline void bfs(){
	que[tot=tow=1]=en;h[en]=1;
	while (tot<=tow){
		for (int u=fi[que[tot]];u;u=ne[u]){
			if (h[j[u]])continue;
			que[++tow]=j[u];
			h[j[u]]=h[que[tot]]+1;
			hs[h[j[u]]]++;
		}
		++tot;
	}
}
int isap(int ro,int flow){
	if (ro==en)return flow;
	int sum=0,flag;
	for (int u=fi[ro];u;u=ne[u])
		if (h[ro]>h[j[u]] && k[u]>0){
			flag=isap(j[u],min(flow-sum,k[u]));
			sum+=flag;
			k[u]-=flag;
			k[u^1]+=flag;
			cur[ro]=u;
			if (sum==flow)return sum;
		}
	if (!(--hs[h[ro]]))h[st]=n+1;
	hs[++h[ro]]++;
	return sum;
}
int main (){
	orzcy(n);orzcy(m);orzcy(st);orzcy(en);
	for (int i=1;i<=m;++i){
		orzcy(x);orzcy(y);orzcy(z);
		addedge(x,y,z);
	}
	bfs();
	while (h[st]<=n){
		for (int i=1;i<=n;++i)cur[i]=fi[i];
		ans+=isap(st,2147483647);
	}
	printf ("%d",ans);
	return 0;
}
