#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,m,h[2005],a,l[2005],r[2005],ans;
int main ()
{
	scanf ("%d",&n);
	for (int b=1;b<=n;++b)
	{
		for (int c=1;c<=n;++c)
		{
			scanf ("%d",&a);
			if (!a)h[c]++;
			else h[c]=0;
		}
		for (int c=1;c<=n;++c)
		{
			l[c]=c;
			while (l[c]>1 && h[l[c]-1]>=h[c])l[c]=l[l[c]-1];
		}
		for (int c=n;c>=1;--c)
		{
			r[c]=c;
			while (r[c]<n && h[r[c]+1]>=h[c])r[c]=r[r[c]+1];
		}
		for (int c=1;c<=n;++c)
			ans=max(ans,h[c]*(r[c]-l[c]+1));
	}
	printf ("%d",ans);
	return 0;
}
