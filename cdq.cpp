#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
const int N=100005;
struct node{int x,y,z,s,val;}a[N],p[N];
bool operator < (node i,node j)
{
	return (i.y==j.y)?(i.z<j.z):(i.y<j.y);
}
bool cmp(node i,node j)
{
	if (i.x==j.x)
		if (i.y==j.y)return i.z<j.z;
		else return i.y<j.y;
	else return i.x<j.x;
}
int n,k,ans[N<<1];
int sum[N<<1];
int lowbit(int x)
{
	return x&(-x);
}
inline void add(int x,int val)
{
	for (;x<=k;x+=lowbit(x))
		sum[x]+=val;
}
inline int query(int x)
{
	int s=0;
	for (;x;x-=lowbit(x))
		s+=sum[x];
	return s;
}
int len;
void solve(int l,int r)
{
	if (l==r)return;
	int mid=(l+r)>>1;
	solve(l,mid);
	solve(mid+1,r);
	sort(p+l,p+mid+1);
	sort(p+mid+1,p+r+1);
	int i,j;
	for (i=l,j=mid+1;j<=r;++j)
	{
		while (i<=mid && p[i].y<=p[j].y)
		{
			add(p[i].z,p[i].val);
			++i;
		}
		p[j].s+=query(p[j].z);
	}
	for (int k=l;k<i;++k)add(p[k].z,-p[k].val);
}
int cnt;
int main ()
{
	scanf ("%d%d",&n,&k);
	for (int i=1;i<=n;++i)scanf ("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;++i)
	{
		cnt++;
		if (a[i].x!=a[i+1].x || a[i].y!=a[i+1].y || a[i].z!=a[i+1].z)
		{
			p[++len]=a[i];
			p[len].val=cnt;
			cnt=0;
		}
	}
	solve(1,len);
	for (int i=1;i<=len;++i)ans[p[i].s+p[i].val-1]+=p[i].val;
	for (int i=0;i<n;++i)printf ("%d\n",ans[i]);
	return 0;
}
/*
10 3
3 3 3
2 3 3
2 3 1
3 1 1
3 1 2
1 3 1
1 1 2
1 2 2
1 3 2
1 2 1
*/
