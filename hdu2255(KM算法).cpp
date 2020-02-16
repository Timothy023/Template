#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn=305;
const int inf=0x3f3f3f3f;
int n;
int linker[maxn],lx[maxn],ly[maxn],slack[maxn];
int visx[maxn],visy[maxn],w[maxn][maxn];
bool dfs (int ro)
{
	visx[ro]=1;
	for (int b=1;b<=n;++b)
	{
		if (visy[b])continue;
		int tmp=lx[ro]+ly[b]-w[ro][b];
		if (tmp==0)
		{
			visy[b]=1;
			if (linker[b]==-1 || dfs(linker[b]))
			{
				linker[b]=ro;
				return true;
			}
		}
		else
			if (slack[b]>tmp)
				slack[b]=tmp;
	}
	return false;
}
int KM()
{
	memset(linker,-1,sizeof(linker));
	for (int b=1;b<=n;++b)
	{	int c;
		for (c=1,lx[b]=-inf;c<=n;++c)
			if (lx[b]<w[b][c])
				lx[b]=w[b][c];
	}
	for (int b=1;b<=n;++b)
	{
		for (int c=1;c<=n;++c)
			slack[c]=inf;
		while (1)
		{
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			if (dfs(b))break;
			int d=inf;
			for (int c=1;c<=n;++c)
				if (d>slack[c] && !visy[c])
					d=slack[c];
			for (int c=1;c<=n;++c)
				if (visx[c])
					lx[c]-=d;
			for (int c=1;c<=n;++c)
				if (visy[c])
					ly[c]+=d;
				else slack[c]-=d;
		}
	}
	int tmp=0;
	for (int b=1;b<=n;++b)
		if (linker[b]!=-1)
			tmp+=w[linker[b]][b];
	return tmp;
}
int main ()
{
	while (~scanf ("%d",&n))
	{
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
				scanf ("%d",&w[i][j]);
		int ans=KM();
		printf ("%d\n",ans);
	}
	return 0;
}
