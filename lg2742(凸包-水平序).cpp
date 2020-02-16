#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=10005;
struct node
{
	double x,y;
	friend bool operator < (node i,node j)
	{
		return (i.y==j.y)?(i.x<j.x):(i.y<j.y);
	}
}poi[N],sta[N<<1];
double cj(double x1,double y1,double x2,double y2)
{
	return x1*y2-x2*y1;
}
double pd(node i,node j,node k)
{
	return cj(j.x-i.x,j.y-i.y,k.x-i.x,k.y-i.y);
}
double dis(node i,node j)
{
	return sqrt((i.x-j.x)*(i.x-j.x)+(i.y-j.y)*(i.y-j.y));
}
double ans;
int n,top,t;
int main ()
{
	scanf ("%d",&n);
	for (int i=1;i<=n;++i)
		scanf ("%lf%lf",&poi[i].x,&poi[i].y);
	sort(poi+1,poi+n+1);
	for (int i=1;i<=n;++i)
	{
		while (top>=2 && pd(sta[top-2],sta[top-1],poi[i])<0)top--;
		sta[top++]=poi[i];
	}
	t=top+1;
	for (int i=n-1;i>=1;--i)
	{
		while (top>=t && pd(sta[top-2],sta[top-1],poi[i])<0)top--;
		sta[top++]=poi[i];
	}
	for (int i=0;i<top-1;++i)ans+=dis(sta[i],sta[i+1]);
	printf ("%.2lf",ans);
	return 0;
}
