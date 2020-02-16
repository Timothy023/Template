#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
struct node
{
	long long x,y,z,cur,wz,cz;
}que[100005],q[100005];
long long a[50005];
long long ans[50005];
long long n,m,step,st;
bool flag[50005];
long long sum[2][200005];
long long lowbit(long long key){return key&(-key);}
long long tot;
void add(int c,int l,int key)
{
	for (;l<=tot;l+=lowbit(l))
		sum[c][l]+=key;
}
long long su(int c,int r)
{
	long long s=0;
	for (;r>0;r-=lowbit(r))
		s+=sum[c][r];
	return s;
}
long long query(int l,int r)
{
	return su(0,r)*r-su(1,r)-su(0,l-1)*(l-1)+su(1,l-1);
}
void jia(int l,int r,int key)
{
	add(0,l,key);
	add(0,r+1,-key);
	add(1,l,(l-1)*key);
	add(1,r+1,-r*key);
}
void ztef(int le,int ri,int l,int r)
{
	int mid=(l+r)>>1;
	if (l==r)
	{
		for (int b=le;b<=ri;++b)
			if (que[b].cz==2)
				ans[que[b].wz]=l;
		return;
	}
	int len1=le,len2=le;
	for (int b=le;b<=ri;++b)
	{
		if (que[b].cz==2)
		{
			long long t=query(que[b].x,que[b].y);
			if (t<que[b].z){flag[b]=0;que[b].z-=t;}
			else {flag[b]=1;len2++;}
		}
		else
		{
			if (que[b].z<=mid){jia(que[b].x,que[b].y,1);flag[b]=1;len2++;}
			else flag[b]=0;
		}
	}
	for (int b=le;b<=ri;++b)
		if (que[b].cz==1 && que[b].z<=mid)
			jia(que[b].x,que[b].y,-1);
	for (int b=le;b<=ri;++b)
		if (flag[b])q[len1++]=que[b];
		else q[len2++]=que[b];
	for (int b=le;b<=ri;++b)
		que[b]=q[b];
	ztef(le,len1-1,l,mid);
	ztef(len1,ri,mid+1,r);
}
int main ()
{
	scanf ("%lld%lld",&n,&m);
	for (int b=1;b<=m;++b)
	{
		scanf ("%lld%lld%lld%lld",&que[b].cz,&que[b].x,&que[b].y,&que[b].z);
		if (que[b].cz==2)que[b].wz=++st;
		else
		{
			que[b].z=n-que[b].z+1;
			tot=max(tot,que[b].z);
		}
	}
	ztef(1,m,1,tot);
	for (int b=1;b<=st;++b)
		printf ("%lld\n",n-ans[b]+1);
	return 0;
}
