#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=2005;
bool flag,vis[N];
int belong[N];
int low[N],ti[N],dfn,sta[N],top,ans;
int t,n,m,xp,x,yp,y;
int fi[N],ne[N],j[N],step;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline int orzcy(){
	int s=0;
	char ch=getchar();
	while (ch!='m' && ch!='h')ch=getchar();
	if (ch=='m')s=read()*2;
	else s=read()*2-1;
	return s;
}
inline void addedge(int fr,int to){
	step++;j[step]=to;
	ne[step]=fi[fr];fi[fr]=step;
}
void tarjan(int ro){
	low[ro]=ti[ro]=++dfn;
	vis[ro]=1;sta[++top]=ro;
	for (int u=fi[ro];u;u=ne[u])
		if (!ti[j[u]]){
			tarjan(j[u]);
			low[ro]=min(low[ro],low[j[u]]);
		}
		else if (vis[j[u]])
			low[ro]=min(low[ro],ti[j[u]]);
	if (low[ro]==ti[ro]){
		++ans;
		int now=0;
		while (now!=ro){
			now=sta[top--];
			belong[now]=ans;
			vis[now]=0;
		}
	}
}
int main (){
	t=read();
	while (t --> 0){
		n=read();m=read();
		ans=step=dfn=0;flag=1;
		for (int i=1;i<=n*2;++i)
			ti[i]=low[i]=fi[i]=ne[i]=0;
		for (int i=1;i<=m;++i){
			x=orzcy();y=orzcy();
			if (x&1)xp=x++;else xp=x--;
			if (y&1)yp=y++;else yp=y--;
			addedge(x,yp);
			addedge(y,xp);
		}
		for (int i=1;i<=2*n;++i)
			if (!ti[i])
				tarjan(i);
		for (int i=1;i<=n;++i)
			if (belong[i*2-1]==belong[i*2]){
				puts("BAD");
				flag=0;
				break;
			}
		if (flag) puts("GOOD");
	}
	return 0;
}
