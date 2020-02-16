#include<iostream>
#include<cstdio>
using namespace std;
int n,a[1000001],len;
void put()
{
	len++;
	int size=len;
	while (size>1)
	{
		int m=size>>1;
		if (a[m]>a[size])
		{
			int t;
			t=a[m];a[m]=a[size];a[size]=t;
		}
		else break;
		size=m;
	}
}
void get()
{
	printf ("%d ",a[1]);
	a[1]=a[len--];
	int now=1;
	while(now*2<=len)
	{
		int next=now*2;
		if (next<len && a[next]>a[next+1])next++;
		if (a[now]<=a[next])break;
		int t;
		t=a[now];a[now]=a[next];a[next]=t;
		now=next;
	}
}
int main ()
{
	cin >>n;
	for (int b=1;b<=n;++b){scanf ("%d",&a[b]);put();}
	for (int b=1;b<=n;++b)get();
	return 0;
}
