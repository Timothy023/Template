#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=50005;
long long ans;
int n,top,q,wz=-1;
struct node{double x,y;}poi[N],t,sta[N];
double cj(node i,node j,node k)
{
	return (j.x-i.x)*(k.y-i.y)-(k.x-i.x)*(j.y-i.y);
}
double dis(node i,node j)
{
	return (i.x-j.x)*(i.x-j.x)+(i.y-j.y)*(i.y-j.y);
}
bool cmp(node i,node j)
{
	double flag=cj(poi[1],i,j);
	if (flag==0)return dis(poi[1],i)>dis(poi[1],j);
	else return flag>0;
}
void graham()
{
	sta[1]=poi[1];sta[2]=poi[2];top=2;
	for (int i=3;i<=n;++i)
	{
		while (top>=2 && cj(sta[top-1],sta[top],poi[i])<0)
			--top;
		sta[++top]=poi[i];
	}
}
double Max(double i,double j)
{
	return i>j?i:j;
}
void rc()
{
	ans=dis(sta[1],sta[2]);
	q=2;
	for (int i=1;i<=top;++i)
	{
		while (fabs(cj(sta[i],sta[i%top+1],sta[q%top+1]))>
			   fabs(cj(sta[i],sta[i%top+1],sta[q])))
			   q=q%top+1;
		ans=Max(ans,Max(dis(sta[i],sta[q]),dis(sta[i%top+1],sta[q])));
	}
	cout <<ans;
}
int main ()
{
	scanf ("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf ("%lf%lf",&poi[i].x,&poi[i].y);
		if (wz==-1 || poi[wz].x>poi[i].x || (poi[wz].x==poi[i].x && poi[wz].y>poi[i].y))wz=i;
	}
	t=poi[1];poi[1]=poi[wz];poi[wz]=t;
	sort(poi+2,poi+n+1,cmp);
	graham();
	rc();
	return 0;
}
