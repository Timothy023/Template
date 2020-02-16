#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
struct node{int x,y;}po[5005];
int n,i,j,l,w,ans;
bool cmp(node a1,node a2)
{
	if (a1.x==a2.x)return a1.y<a2.y;
	else return a1.x<a2.x;
}
int main ()
{
	scanf ("%d%d",&l,&w);
	scanf ("%d",&n);
	po[1].x=0;po[1].y=0;
	po[2].x=l;po[2].y=0;
	po[3].x=0;po[3].y=w;
	po[4].x=l;po[4].y=w;
	n+=4;
	for (int b=5;b<=n;++b)
		scanf ("%d%d",&po[b].x,&po[b].y);
	sort(po+1,po+n+1,cmp);
	for (int b=1;b<=n;++b)
	{
		int u=0,v=w;
		for (int c=b+1;c<=n;++c)
		{
			if (po[b].x==po[c].x || po[c].y<u || po[c].y>v)continue;
			ans=max(ans,(po[c].x-po[b].x)*(v-u));
			if (po[c].y>u && po[c].y<=po[b].y)u=po[c].y;
			if (po[c].y<v && po[c].y>=po[b].y)v=po[c].y;
			if (u>=v)break;
		}
	}
	printf ("%d",ans);
	return 0;
}
