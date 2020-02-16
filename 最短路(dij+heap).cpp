#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
inline void orzcy(int &s)
{
	s=0;int f=1;char ch=getchar();
	while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){s=s*10+ch-'0';ch=getchar();}
	s*=f;
}
int n,m,s,len;
int dis[10005];
bool flag[10005];
int fan[10005];
int i[1000005],j[1000005],k[1000005],first[500005],next[1000005];
struct node
{
	int val,xh;
	friend bool operator <= (node i,node j){return i.val<=j.val;}
}dui[10005];
inline void pop()
{
	dui[1]=dui[len--];
	fan[dui[1].xh]=1;
	int now=1;
	while (now*2<=len)
	{
		int next=now<<1;
		if (next<len && dui[next+1]<=dui[next])next++;
		if (dui[now]<=dui[next])break;
		fan[dui[now].xh]^=fan[dui[next].xh]^=fan[dui[now].xh]^=fan[dui[next].xh];
		node tt=dui[now];
		dui[now]=dui[next];
		dui[next]=tt;
		now=next;
	}
}
inline void pop1(int now)
{
	while (now>1)
	{
		int next=now>>1;
		if (dui[now]<=dui[next])
		{
			fan[dui[now].xh]^=fan[dui[next].xh]^=fan[dui[now].xh]^=fan[dui[next].xh];
			node tt=dui[now];
			dui[now]=dui[next];
			dui[next]=tt;
		}
		else break;
		now=next;
	}
}
int main ()
{
	orzcy(n);orzcy(m);orzcy(s);
	for (int b=1;b<=n;++b)dis[b]=2147483647;
	for (int b=1;b<=m;++b)
	{
		orzcy(i[b]);orzcy(j[b]);orzcy(k[b]);
		next[b]=first[i[b]];first[i[b]]=b;
	}
	dui[1].val=0;dui[1].xh=s;len=1;fan[s]=1;
	for (int b=1;b<=n;++b)
		if (b!=s)
		{
			dui[++len].val=2147483647;
			dui[len].xh=b;
			fan[b]=len;
		}
	for (int b=1;b<=n;++b)
	{
		dis[dui[1].xh]=dui[1].val;
		node y=dui[1];
		pop();
		fan[y.xh]=n+1;
		for (int u=first[y.xh];u;u=next[u])
			if (dis[i[u]]+k[u]<dui[fan[j[u]]].val)
			{
				dui[fan[j[u]]].val=dis[i[u]]+k[u];
				pop1(fan[j[u]]);
			}
	}
	for (int b=1;b<=n;++b)printf ("%d ",dis[b]);
	return 0;
}
