#include<iostream>
#include<cstdlib>
#include<cstdio>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
const int N=400001;
int n,m,mod;
long long t[N<<1],cc[N<<1],cj[N<<1];
inline void pushup(int rt)
{
	t[rt]=(t[rt<<1]+t[rt<<1|1])%mod;
}
inline void pushdown(int l,int r,int rt)
{
	int mid=(l+r)>>1;
	cc[rt<<1]=cc[rt<<1]*cc[rt]%mod;
	cc[rt<<1|1]=cc[rt<<1|1]*cc[rt]%mod;
	
	cj[rt<<1]=(cj[rt<<1]*cc[rt]%mod+cj[rt])%mod;
	cj[rt<<1|1]=(cj[rt<<1|1]*cc[rt]%mod+cj[rt])%mod;
	
	t[rt<<1]=(t[rt<<1]*cc[rt]%mod+cj[rt]*(mid-l+1)%mod)%mod;
	t[rt<<1|1]=(t[rt<<1|1]*cc[rt]%mod+cj[rt]*(r-mid)%mod)%mod;
	
	cc[rt]=1;cj[rt]=0;
}
void build (int l,int r,int rt)
{
	cc[rt]=1;
	if (l==r)
	{
		scanf ("%lld",&t[rt]);
		t[rt]%=mod;
		return;
	}
	int mid=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}
long long query(int l,int r,int rt,int L,int R)
{
	pushdown(l,r,rt);
	if (L<=l && r<=R)return t[rt];
	int mid=(l+r)>>1;
	long long s=0;
	if (L<=mid)s=query(lson,L,R);
	if (mid<R)s+=query(rson,L,R);
	pushup(rt);
	return s%mod;
}
void updatej(int l,int r,int rt,int L,int R,int K)
{
	pushdown(l,r,rt);
	if (L<=l && r<=R)
	{
		t[rt]=(t[rt]+(r-l+1)*K)%mod;
		cj[rt]=K;
		return;
	}
	int mid=(l+r)>>1;
	if (L<=mid)updatej(lson,L,R,K);
	if (mid<R)updatej(rson,L,R,K);
	pushup(rt);
}
void updatec(int l,int r,int rt,int L,int R,int K)
{
	pushdown(l,r,rt);
	if (L<=l && r<=R)
	{
		t[rt]=t[rt]*K%mod;
		cc[rt]=K;
		return;
	}
	int mid=(l+r)>>1;
	if (L<=mid)updatec(lson,L,R,K);
	if (mid<R)updatec(rson,L,R,K);
	pushup(rt);
}
int main ()
{
	scanf ("%d%d%d",&n,&m,&mod);
	build(1,n,1);
	for (int i=1;i<=m;++i)
	{
		int x,y,z,k;
		scanf ("%d%d%d",&k,&x,&y);
		if (k==3)printf ("%lld\n",query(1,n,1,x,y));
		else if (k==2)
		{
			scanf ("%d",&z);
			updatej(1,n,1,x,y,z);
		}
		else
		{
			scanf ("%d",&z);
			updatec(1,n,1,x,y,z);
		}
	}
	return 0;
}
/*	
7 5 43
1 2 3 4 5 6 7 
1 2 5 5 
3 2 4
2 3 7 9
3 1 3 
3 4 7
*/
