#include<iostream>
using namespace std;
int ans[101],n,m,i[1001],j[1001],k[1001];
int main ()
{
	scanf ("%d%d",&n,&m);
	for (int b=1;b<=m;++b)scanf ("%d%d%d",&i[b],&j[b],&k[b]);
	for (int b=1;b<=n;++b)ans[b]=999999999;
	ans[1]=0;
	for (int b=1;b<=n-1;++b)
	  for (int c=1;c<=m;++c)
	    ans[j[c]]=min(ans[j[c]],ans[i[c]]+k[c]);
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
