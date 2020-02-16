#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int n,sum;
int ans,x[100001],y[100001],len[200001];
bool flag[200001];
int main ()
{
	scanf ("%d",&n);
	for (int b=1;b<=n;++b)
	{
		scanf ("%d%d",&x[b],&y[b]);
		len[++sum]=x[b];
		len[++sum]=y[b];
	}
	sort(len+1,len+sum+1);
	for (int b=1;b<=n;++b)
	{
		int i,j;
		for (i=1;i<=sum;++i)if (len[i]==x[b])break;
		for (j=1;j<=sum;++j)if (len[j]==y[b])break;
		for (int c=i;c<j;++c)flag[c]=true;
	}
	for (int b=1;b<=sum;++b)ans+=(len[b+1]-len[b])*flag[b];
	printf ("%d",ans);
	return 0;
}
