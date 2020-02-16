#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,m,s;
int i[1000005],j[1000005],first[500005],next[1000005];
inline void orzcy(int &ss)
{
	ss=0;int f=1;char ch=getchar();
	while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){ss=ss*10+ch-'0';ch=getchar();}
	ss*=f;
}
int maxson[500005],sum[500005],fa[500005],deep[500005];
void dfs1(int ro)
{
	sum[ro]=1;
	for (int u=first[ro];u;u=next[u])
		if (!sum[j[u]])
		{
			deep[j[u]]=deep[ro]+1;
			fa[j[u]]=ro;
			dfs1(j[u]);
			sum[ro]+=sum[j[u]];
			maxson[ro]=sum[maxson[ro]]>sum[j[u]]?maxson[ro]:j[u];
		}
}
int top[500005],dfn[500005],len;
void dfs2(int ro,int t)
{
	top[ro]=t;
	dfn[ro]=++len;
	if (maxson[ro])dfs2(maxson[ro],t);
	for (int u=first[ro];u;u=next[u])
		if (!dfn[j[u]])
			dfs2(j[u],j[u]);
}
inline void oyzcy(int x)
{
	if (x>=10)oyzcy(x/10);
	putchar(x%10+'0');
}
int main ()
{
	orzcy(n);
	orzcy(m);
	orzcy(s);
	for (int b=1;b<n;++b)
	{
		orzcy(i[b]);orzcy(j[b]);
		next[b]=first[i[b]];first[i[b]]=b;
		j[b+n]=i[b];i[b+n]=j[b];
		next[b+n]=first[i[b+n]];first[i[b+n]]=b+n;
	}
	dfs1(s);
	dfs2(s,s);
	for (int b=1;b<=m;++b)
	{
		int l,r;
		orzcy(l);
		orzcy(r);
		while (top[l]!=top[r])
		{
			if (deep[top[l]]<deep[top[r]])r=fa[top[r]];
			else l=fa[top[l]];
		}
		if (deep[l]<deep[r])oyzcy(l);
		else oyzcy(r);
		puts("");
	}
	return 0;
}
