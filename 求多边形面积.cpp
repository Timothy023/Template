#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,ans;
struct node{int x,y;}poi[105];
int cj(node i,node j){return i.x*j.y-j.x*i.y;}
int main ()
{
	scanf ("%d",&n);
	for (int i=0;i<n;++i)scanf ("%d%d",&poi[i].x,&poi[i].y);
	for (int i=0;i<n;++i)ans+=cj(poi[i],poi[(i+1)%n]);
	printf ("%d",ans/2);
	return 0;
}
