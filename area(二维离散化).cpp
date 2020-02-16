#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
long long n,x1[5001],x2[5001],y1[5001],y2[5001],lenx[10001],leny[10001],sum,ans;
bool flag[10001][10001];
int main ()
{
	freopen ("area.in","r",stdin);
	freopen ("area.out","w",stdout);
	cin >>n;
	for (int b=1;b<=n;++b)
	{
		cin >>x1[b]>>y1[b]>>x2[b]>>y2[b];
		lenx[++sum]=x1[b];
		leny[sum]=y1[b];
		lenx[++sum]=x2[b];
		leny[sum]=y2[b];
	}
	sort(lenx+1,lenx+sum+1);
	sort(leny+1,leny+sum+1);
	for (int b=1;b<=n;++b)
	{
		int i,j,k,l;
		for(i=1;i<=sum;++i)if (lenx[i]==x1[b])break;
		for(j=1;j<=sum;++j)if (lenx[j]==x2[b])break;
		for(k=1;k<=sum;++k)if (leny[k]==y1[b])break;
		for(l=1;l<=sum;++l)if (leny[l]==y2[b])break;
		for (int c=i;c<j;++c)
		  for (int d=k;d<l;++d)
		    flag[c][d]=true;
	}
	for (int b=1;b<=sum;++b)
	  for (int c=1;c<=sum;++c)
	    ans+=(lenx[b+1]-lenx[b])*(leny[c+1]-leny[c])*flag[b][c];
	cout <<ans;
}
