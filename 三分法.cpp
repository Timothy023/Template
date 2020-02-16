#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
double l,r,a[15],q,p;
inline double f(double x)
{
	double s=1,sum=0;
	for (int b=n+1;b>=1;--b,s*=x)
		sum+=s*a[b];
	return sum;
}
int main ()
{
	scanf ("%d%lf%lf",&n,&l,&r);
	for (int b=1;b<=n+1;++b)scanf ("%lf",&a[b]);
	while (fabs(l-r)>=1e-6)
	{
		p=l+(r-l)/3;
		q=l+(r-l)*2/3;
		if (f(p)>f(q))r=q;
		else l=p;
	}
	printf ("%.5lf",l);
	return 0;
}
