#include<iostream>
#include<cstdio>
using namespace std;
const int inf=1073741823;
int map[101][101],ans[101],n,m,i,j,k;
bool jc[101];
int main()
{
	scanf("%d%d",&n,&m);
	for(int b=1;b<=n;++b)for(int c=1;c<=n;++c)if (b!=c)map[b][c]=inf;
	for(int b=1;b<=m;++b){scanf("%d%d%d",&i,&j,&k);map[i][j]=k;}
	jc[1]=true;for (int b=1;b<=n;++b)ans[b]=map[1][b];
	for (int b=1;b<=n-1;++b)
	{
		int minn=inf,i=-1;
		for (int c=1;c<=n;++c)if (!jc[c] && ans[c]<minn){minn=ans[c];i=c;}
		if (i==-1)break;
		jc[i]=true;
		for (int c=1;c<=n;++c)ans[c]=min(ans[c],ans[i]+map[i][c]);
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
