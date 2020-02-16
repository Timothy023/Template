#include<iostream>
using namespace std;
const int inf=999999999;
int map[101][101],n,m,i,j,k,ans,dis[101],sum;
bool jc[101];
int main ()
{
	scanf ("%d%d",&n,&m);
	for (int b=1;b<=n;++b)for (int c=1;c<=n;++c)if (b!=c)map[b][c]=inf;
	for (int b=1;b<=n;++b){scanf ("%d%d%d",&i,&j,&k);map[i][j]=k;}
	for (int b=1;b<=n;++b)
	{
		for (int c=1;c<=n;++c)
		  printf ("%-12d",map[b][c]);
		cout <<endl;
	}
	cout <<endl;
	for (int b=1;b<=n;++b)dis[b]=map[1][b];
	for (int b=1;b<=n;++b)cout <<dis[b]<<"  ";cout <<endl;
	jc[1]=1;sum=1;
	while (sum<n)
	{
		int minn=inf,wz=-1;
		for (int b=1;b<=n;++b)if (!jc[b] && dis[b]<minn){minn=dis[b];wz=b;}
		cout <<wz<<endl;
		sum++;ans+=dis[wz];jc[wz]=true;
		for (int b=1;b<=n;++b)
			if (!jc[b] && dis[b]>map[wz][b])dis[b]=map[wz][b];
		for (int b=1;b<=n;++b)cout <<dis[b]<<"  ";cout <<endl<<"*************************"<<endl;
	}
	printf ("%d",ans);
	return 0;
}
