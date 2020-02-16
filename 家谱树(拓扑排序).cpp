#include<iostream>
#include<cstdio>
using namespace std;
int ans[1001],c[1001],r[1001],a[1001][1001],n,j,tot,tow,num,temp;
int main ()
{
	scanf ("%d",&n);
	for (int b=1;b<=n;++b)
	{
		do
		{
			scanf ("%d",&j);
			if (j!=0)
			{
				c[b]++;
				r[j]++;
				a[b][c[b]]=j;
			}
		}while (j!=0);
	}
	for (int b=1;b<=n;++b)if (r[b]==0)ans[++tow]=b;
	tot=1;
	do
	{
		temp=ans[tot++];
		printf ("%d ",temp);
		num++;
		for (int b=1;b<=c[temp];++b)
		{
			r[a[temp][b]]--;
			if (r[a[temp][b]]==0)ans[++tow]=a[temp][b];
		}
	}while (num<n);
	return 0;
}
