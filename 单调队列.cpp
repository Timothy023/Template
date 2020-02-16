#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,m,tot=1,tow,a;
struct node{int tim,val;}que[2000005];
int main ()
{
	scanf ("%d%d",&n,&m);
	for (int b=1;b<=n;++b)
	{
		scanf ("%d",&a);
		for (;tot<tow && que[tot].tim<b-m;tot++);
		printf ("%d\n",que[tot].val);
		for (;tot<=tow && que[tow].val>a;--tow);
		que[++tow].val=a;
		que[tow].tim=b;
	}
	return 0;
}
