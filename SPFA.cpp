#include<iostream>
#include<cstdio>
using namespace std;
int ans[101],n,m,i[1001],j[1001],k[1001],que[101],tot,tow,first[101],next[1001];
bool jc[101];
int main ()
{
	scanf ("%d%d",&n,&m);
	for (int b=1;b<=n;++b)first[b]=-1;
	for (int b=1;b<=m;++b)
	{
		scanf ("%d%d%d",&i[b],&j[b],&k[b]);
		next[b]=first[i[b]];
		first[i[b]]=b;
	}
	for (int b=1;b<=n;++b)ans[b]=999999999;
	ans[1]=0;
	tot=tow=1;
	que[tot]=1;
	while (tot<=tow)
	{
		jc[que[tot]]=false;
		int dian=first[que[tot]];
		while (dian!=-1)
		{
			if (ans[i[dian]]+k[dian]<ans[j[dian]])
			{
				ans[j[dian]]=ans[i[dian]]+k[dian];
				if (!jc[j[dian]])
				{
					que[++tow]=j[dian];
					jc[j[dian]]=true;
				}
			}
			dian=next[dian];
		}
		tot++;
	}
	for (int b=1;b<=n;++b)printf ("%d ",ans[b]);
	return 0;
}
/*
5 8
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3
*/
