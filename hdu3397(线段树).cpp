#include<iostream>
#include<cstdlib>
#include<cstdio>
#define maxn 100005
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
int lsum1[maxn<<2],rsum1[maxn<<2],msum1[maxn<<2],sum1[maxn<<2],col[maxn<<2];
int lsum0[maxn<<2],rsum0[maxn<<2],msum0[maxn<<2],sum0[maxn<<2],num[maxn];
int n,m,step;
void pushup(int rt,int mid,int m)
{
	msum1[rt]=max(max(msum1[rt<<1],msum1[rt<<1|1]),rsum1[rt<<1]+lsum1[rt<<1|1]);
	lsum1[rt]=max(lsum1[rt<<1],(lsum1[rt<<1]+lsum1[rt<<1|1])*(lsum1[rt<<1]==m-(m>>1)));
	rsum1[rt]=max(rsum1[rt<<1|1],(rsum1[rt<<1]+rsum1[rt<<1|1])*(rsum1[rt<<1|1]==(m>>1)));
	
	msum0[rt]=max(max(msum0[rt<<1],msum0[rt<<1|1]),rsum0[rt<<1]+lsum0[rt<<1|1]);
	lsum0[rt]=max(lsum0[rt<<1],(lsum0[rt<<1]+lsum0[rt<<1|1])*(lsum0[rt<<1]==m-(m>>1)));
	rsum0[rt]=max(rsum0[rt<<1|1],(rsum0[rt<<1]+rsum0[rt<<1|1])*(rsum0[rt<<1|1]==(m>>1)));
	
	sum1[rt]=sum1[rt<<1]+sum1[rt<<1|1];
	sum0[rt]=sum0[rt<<1]+sum0[rt<<1|1];
	
//	cout <<msum1[rt]<<"  "<<lsum1[rt]<<"  "<<rsum1[rt]<<"  "<<sum1[rt]<<"  pushup1"<<endl;
//	cout <<msum0[rt]<<"  "<<lsum0[rt]<<"  "<<rsum0[rt]<<"  "<<sum0[rt]<<"  pushup0"<<endl;
//	cout <<rt<<"  "<<mid<<"  "<<m<<"****************"<<endl;system ("pause");
}
void pushdown(int rt,int mid,int m)
{
	if(col[rt]==0)
	{
		lsum1[rt<<1]=rsum1[rt<<1]=msum1[rt<<1]=0;
		lsum0[rt<<1]=rsum0[rt<<1]=msum0[rt<<1]=m-(m>>1);
		lsum1[rt<<1|1]=rsum1[rt<<1|1]=msum1[rt<<1|1]=0;
		lsum0[rt<<1|1]=rsum0[rt<<1|1]=msum0[rt<<1|1]=m>>1;
		sum1[rt<<1]=sum1[rt<<1|1]=0;
		sum0[rt<<1]=m-(m>>1);sum0[rt<<1|1]=m>>1;
		col[rt<<1]=col[rt<<1|1]=col[rt];
	}
	else if (col[rt]==1)
		{
			lsum1[rt<<1]=rsum1[rt<<1]=msum1[rt<<1]=m-(m>>1);
			lsum0[rt<<1]=rsum0[rt<<1]=msum0[rt<<1]=0;
			lsum1[rt<<1|1]=rsum1[rt<<1|1]=msum1[rt<<1|1]=m>>1;
			lsum0[rt<<1|1]=rsum0[rt<<1|1]=msum0[rt<<1|1]=0;
			sum0[rt<<1]=sum0[rt<<1|1]=0;
			sum1[rt<<1]=m-(m>>1);sum1[rt<<1|1]=m>>1;
			col[rt<<1]=col[rt<<1|1]=col[rt];
		}
	else if (col[rt]==2)
		{
			int t;
			t=lsum1[rt<<1];lsum1[rt<<1]=lsum0[rt<<1];lsum0[rt<<1]=t;
			t=rsum1[rt<<1];rsum1[rt<<1]=rsum0[rt<<1];rsum0[rt<<1]=t;
			t=msum1[rt<<1];msum1[rt<<1]=msum0[rt<<1];msum0[rt<<1]=t;
			t=sum1[rt<<1];sum1[rt<<1]=sum0[rt<<1];sum0[rt<<1]=t;
			if (col[rt<<1]>-1)
				if (col[rt<<1]!=2)col[rt<<1]=!col[rt<<1];
				else col[rt<<1]=-1;
			else col[rt<<1]=col[rt];
			t=lsum1[rt<<1|1];lsum1[rt<<1|1]=lsum0[rt<<1|1];lsum0[rt<<1|1]=t;
			t=rsum1[rt<<1|1];rsum1[rt<<1|1]=rsum0[rt<<1|1];rsum0[rt<<1|1]=t;
			t=msum1[rt<<1|1];msum1[rt<<1|1]=msum0[rt<<1|1];msum0[rt<<1|1]=t;
			t=sum1[rt<<1|1];sum1[rt<<1|1]=sum0[rt<<1|1];sum0[rt<<1|1]=t;
			if (col[rt<<1|1]>-1)
				if (col[rt<<1|1]!=2)col[rt<<1|1]=!col[rt<<1|1];
				else col[rt<<1|1]=-1;
			else col[rt<<1|1]=col[rt];
		}
	col[rt]=-1;
}
void build(int l,int r,int rt)
{
	col[rt]=-1;
	if (l==r)
	{
		scanf ("%d",&num[l]);
		if (num[l]==1)
		{
			lsum1[rt]=rsum1[rt]=msum1[rt]=sum1[rt]=1;
			lsum0[rt]=rsum0[rt]=msum0[rt]=sum0[rt]=0;
		}
		else
		{
			lsum1[rt]=rsum1[rt]=msum1[rt]=sum1[rt]=0;
			lsum0[rt]=rsum0[rt]=msum0[rt]=sum0[rt]=1;
		}
		return;
	}
	int mid=(l+r)>>1;
	build(lson);build(rson);
	pushup(rt,mid,r-l+1);
}
void update(int l,int r,int rt,int i,int j,int k)
{
//	cout <<msum1[rt]<<"  "<<lsu.m1[rt]<<"  "<<rsum1[rt]<<"  "<<sum1[rt]<<endl;
//	cout <<msum0[rt]<<"  "<<lsum0[rt]<<"  "<<rsum0[rt]<<"  "<<sum0[rt]<<endl;
//	cout <<l<<"  "<<r<<"  "<<rt<<"  "<<i<<"  "<<j<<"  "<<k<<"  "<<col[rt]<<endl;system ("pause");
//	cout <<msum1[rt]<<"  "<<l<<"  "<<r<<"+++++++++++++++"<<endl;system ("pause");
	if (i<=l && r<=j)
	{
		if(k==0)
		{
			lsum1[rt]=rsum1[rt]=msum1[rt]=sum1[rt]=0;
			lsum0[rt]=rsum0[rt]=msum0[rt]=sum0[rt]=r-l+1;
			col[rt]=k;
		}
		else if (k==1)
			{
				lsum1[rt]=rsum1[rt]=msum1[rt]=sum1[rt]=r-l+1;
				lsum0[rt]=rsum0[rt]=msum0[rt]=sum0[rt]=0;
				col[rt]=k;
			}
		else if (k==2)
			{
				
				int t;
				t=lsum1[rt];lsum1[rt]=lsum0[rt];lsum0[rt]=t;
				t=rsum1[rt];rsum1[rt]=rsum0[rt];rsum0[rt]=t;
				t=msum1[rt];msum1[rt]=msum0[rt];msum0[rt]=t;
				t=sum1[rt];sum1[rt]=sum0[rt];sum0[rt]=t;
				if (col[rt]>-1)
					if (col[rt]!=2)col[rt]=!col[rt];
					else col[rt]=-1;
				else col[rt]=k;
			}
//		cout <<msum1[rt]<<"  "<<l<<"  "<<r<<"---------------"<<endl;system ("pause");
		return;
	}
	int mid=(l+r)>>1;
	if (col[rt]>-1)pushdown(rt,mid,r-l+1);
	if (i<=mid)update(lson,i,j,k);
	if (j>mid)update(rson,i,j,k);
//	cout <<l<<"  "<<r<<endl;
	pushup(rt,mid,r-l+1);
//	cout <<msum1[rt]<<"  "<<l<<"  "<<r<<"_______________________"<<endl;system ("pause");
}
int query(int l,int r,int rt,int i,int j)
{
//	cout <<l<<"  "<<r<<"  "<<rt<<"  "<<i<<"  "<<j<<"  "<<sum1[rt]<<endl;system ("pause");
	if (i<=l && r<=j)return sum1[rt];
	int mid=(l+r)>>1,o=0;
	if (col[rt]>-1)pushdown(rt,mid,r-l+1);
	if (i<=mid)o=query(lson,i,j);
	if (j>mid)o+=query(rson,i,j);
	return o;
}
int query1(int l,int r,int rt,int i,int j)
{
	if (i<=l && r<=j)return msum1[rt];
	int mid=(l+r)>>1;
	if (col[rt]>-1)pushdown(rt,mid,r-l+1);
	if (j<=mid)return query1(lson,i,j);
	if (i>mid)return query1(rson,i,j);
	return max(max(query1(lson,i,j),query1(rson,i,j)),
				(min(rsum1[rt<<1],mid-i+1)+min(lsum1[rt<<1|1],j-mid)));
}
int main ()
{
	scanf ("%d",&step);
	while (step--)
	{
		scanf ("%d%d",&n,&m);
		build(1,n,1);
		for (int b=1;b<=m;++b)
		{
			int i,j,k;
//			cout <<"msum[2]="<<msum1[2]<<endl;
			scanf ("%d%d%d",&i,&j,&k);
			if (i<=2)update(1,n,1,j+1,k+1,i);
			if (i==3)printf ("%d\n",query(1,n,1,j+1,k+1));
			if (i==4)printf ("%d\n",query1(1,n,1,j+1,k+1));
		}
	}
	return 0;
}
