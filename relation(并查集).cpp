#include<iostream>
using namespace std;
int f[100001],n,m,i,j,p;
int getf(int v)
{
	if (f[v]!=v)f[v]=getf(f[v]);
	return f[v];
}
void hb(int a1,int a2)
{
	int t1,t2;
	t1=getf(a1);
	t2=getf(a2);
	if (t1!=t2)f[t2]=t1;
}
int main ()
{
	freopen ("relation.in","r",stdin);
	freopen ("relation.out","w",stdout);
	scanf ("%d%d",&n,&m);
	for (int b=1;b<=n;++b)f[b]=b;
	for (int b=1;b<=m;++b)
	{
		scanf ("%d%d",&i,&j);
		hb(i,j);
	}
	scanf ("%d",&p);
	for (int b=1;b<=p;++b)
	{
		scanf ("%d%d",&i,&j);
		printf ("%s\n",getf(i)==getf(j)?"Yes":"No");
	}
	return 0;
}
