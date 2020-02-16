#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
const int n=3;
struct node{double x,y;}poi[10],p;
double cj(double x1,double y1,double x2,double y2)
{
	return x1*y2-x2*y1;
}
double pd(node i,node j,node k)
{
	return cj(j.x-i.x,j.y-i.y,k.x-i.x,k.y-i.y);
}
int sum;
char c1,c2,c3;
int main ()
{
	for (int i=1;i<=n;++i)
		cin >>c1>>poi[i].x>>c2>>poi[i].y>>c3;
	cin >>c1>>p.x>>c2>>p.y>>c3;
	for (int i=1;i<=n;++i)
		if (poi[i].x==p.x && poi[i].y==p.y)
		{
			puts("4");
			return 0;
		}
	for (int i=1;i<=n;++i)
	{
		node low,hei;
		if (poi[i].y==poi[i%n+1].y)continue;
		if (poi[i].y<poi[i%n+1].y)
		{
			low=poi[i];
			hei=poi[i%n+1];
		}
		else
		{
			low=poi[i%n+1];
			hei=poi[i];
		}
		double flag=pd(low,p,hei);
		if (low.y<p.y && p.y<=hei.y)
		{
			if (fabs(flag)<=1e-6)
			{
				puts("3");
				return 0;
			}
			else if (flag<0)
				sum++;
		}
	}
	if (sum & 1)puts("1");
	else puts("2");
	return 0;
}
