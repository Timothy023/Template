#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
struct node{double x,y;}poi[10005],t;
double lx(node i,node j,node yd)
{
	return (i.y-yd.y)*(j.x-yd.x)-(j.y-yd.y)*(i.x-yd.x);
}
double dis(node i,node j)
{
	return sqrt((i.x-j.x)*(i.x-j.x)+(i.y-j.y)*(i.y-j.y));
}
bool cmp(node i,node j)
{
	double h=lx(i,j,poi[1]);
	if (h==0)return dis(poi[1],i)<dis(poi[1],j);
	else return h<0;
}
int n,k=-1;
int que[10005],tot;
double ans=0;
int main ()
{
	scanf ("%d",&n);
	for (int b=1;b<=n;++b)
	{
		scanf ("%lf%lf",&poi[b].x,&poi[b].y);
		if (k==-1 || poi[b].y<poi[k].y || (poi[k].y==poi[b].y && poi[b].x<poi[k].x))k=b;
	}
	t=poi[1];poi[1]=poi[k];poi[k]=t;
	sort(poi+2,poi+n+1,cmp);
	tot=3;
	que[1]=1;que[2]=2;que[3]=3;
	for (int b=4;b<=n;++b)
	{
		while (tot && lx(poi[que[tot]],poi[b],poi[que[tot-1]])>=0)tot--;
		que[++tot]=b;
	}
	que[++tot]=1;
	for (int b=1;b<tot;++b)
		ans+=dis(poi[que[b]],poi[que[b+1]]);
	printf ("%.2lf",ans);
	return 0;
}
