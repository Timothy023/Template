#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,v,f[200005];
int kind[11][11];
int q1[200005],q2[200005],tot1,tow1,tot2,tow2;
int main ()
{
	freopen ("medic2.in","r",stdin);
	freopen ("medic2.out","w",stdout);
	scanf ("%d%d",&n,&v);
	for(int b=1;b<=n;++b)
	{
		int w,c;
		scanf ("%d%d",&c,&w);
		kind[c][w]++;
	}
	for (int c=1;c<=10;++c)
		for (int w=1;w<=10;++w)
		{
			if (!kind[c][w])continue;
			if (kind[c][w]==1)
			{
				for (int j=v;j>=c;--j)
					f[j]=max(f[j],f[j-c]+w);
				continue;
			}
			if (kind[c][w]*c>=v)
			{
				for (int j=c;j<=v;++j)
					f[j]=max(f[j],f[j-c]+w);
				continue;
			}
			for (int j=0;j<c;++j)
			{
				tot1=tow1=0;
				tot2=tow2=0;
				int cnt=0,t;
				for (int k=j;k<=v;k+=c)
				{
					if (tow1-tot1==kind[c][w]+1)
					{
						if (q1[tot1+1]==q2[tot2+1])tot2++;
						tot1++;
					}
					t=f[k]-cnt*w;
					q1[++tow1]=t;
					for (;tot2<tow2 && q2[tow2]<t;tow2--);
					q2[++tow2]=t;
					f[k]=q2[tot2+1]+cnt*w;
					cnt++;
				}
			}
		}
	printf ("%d",f[v]);
	return 0;
}
/*
9 9
1 2
1 2
1 2
1 2
1 2
3 5
3 5
5 5
9 1
*/
