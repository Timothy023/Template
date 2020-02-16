#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
const int root=1;
map<int,int>ne[100005];
int n,m,le,a,len=1,now,fail[100005];
int que[100005],tot,tow=1;
vector<int>nam[20005],st[100005],v,ma;
int vis[100005],mark[100005],ans1[100005],ans2[100005];
void orzcy(int &s)
{
	s=0;int f=1;char ch=getchar();
	while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){s=s*10+ch-'0';ch=getchar();}
	s*=f;
}
int main ()
{
	orzcy(n);orzcy(m);
	for (int b=-1;b<=10000;++b)
		ne[0][b]=1;
	fail[1]=0;len=1;
	for (int b=1;b<=n;++b)
	{
		orzcy(le);
		for (int c=1;c<=le;++c)
		{
			orzcy(a);
			nam[b].push_back(a);
		}
		nam[b].push_back(-1);
		orzcy(le);
		for (int c=1;c<=le;++c)
		{
			orzcy(a);
			nam[b].push_back(a);
		}
	}
	for (int b=1;b<=m;++b)
	{
		orzcy(le);
		now=root;
		for (int c=1;c<=le;++c)
		{
			orzcy(a);
			if (!ne[now][a])ne[now][a]=++len;
			now=ne[now][a];
		}
		st[now].push_back(b);
	}
	que[0]=1;
	tot=0;tow=1;
	while (tot!=tow)
	{
		now=que[tot];++tot;
		for (map<int,int>::iterator i=ne[now].begin();i!=ne[now].end();++i)
		{
			int t=i->first,k=fail[now];
			while (!ne[k][t])k=fail[k];
			fail[i->second]=ne[k][t];
			que[tow++]=i->second;
		}
	}
	for (int b=1;b<=n;++b)
	{
		now=root;
		for (int c=0;c<nam[b].size();++c)
		{
			int t=nam[b][c];
			while (!ne[now][t])now=fail[now];
			now=ne[now][t];
			for (int d=now;d;d=fail[d])
			{
				if (!vis[d])
				{
					vis[d]=1;v.push_back(d);
					for (int e=0;e<st[d].size();++e)
					{
						if (!mark[st[d][e]])
						{
							mark[st[d][e]]=1;
							ma.push_back(st[d][e]);
							ans1[st[d][e]]++;
							ans2[b]++;
						}
					}
				}
				else break;
			}
		}
		for (int c=0;c<v.size();++c)vis[v[c]]=0;
		for (int c=0;c<ma.size();++c)mark[ma[c]]=0;
		v.clear();
		ma.clear();
	}
	for (int b=1;b<=m;++b)printf ("%d\n",ans1[b]);
	for (int b=1;b<=n;++b)
	{
		printf ("%d",ans2[b]);
		if (b!=n)printf(" ");
	}
	return 0;
}
