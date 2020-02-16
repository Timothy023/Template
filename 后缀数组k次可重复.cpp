#include<iostream>
#include<cstdlib>
#include<cstdio> 
using namespace std;
const int maxn=20005;
const int mnum=1000005;
int sa[maxn],height[maxn],len,num[maxn],rank[maxn];
int a1[maxn],a2[maxn],ss[mnum+5],ans,step;
bool cmp(int *r,int i,int j,int le)
{
	return (r[i]==r[j] && r[i+le]==r[j+le]);
}
void sa_get(int n,int m)
{
	int *x=a1,*y=a2,*t,i,j,p;
	for (i=0;i<n;++i)ss[x[i]=num[i]]++;
	for (i=1;i<m;++i)ss[i]+=ss[i-1];
	for (i=n-1;i>=0;--i)sa[--ss[x[i]]]=i;
	for (j=1,p=1;p<n;j<<=1,m=p)
	{
		for (p=0,i=n-j;i<n;++i)y[p++]=i;
		for (i=0;i<n;++i)if (sa[i]>=j)y[p++]=sa[i]-j;
		for (i=0;i<m;++i)ss[i]=0;
		for (i=0;i<n;++i)ss[x[y[i]]]++;
		for (i=1;i<m;++i)ss[i]+=ss[i-1];
		for (i=n-1;i>=0;--i)sa[--ss[x[y[i]]]]=y[i];
		for (t=x,x=y,y=t,x[sa[0]]=0,i=1,p=1;i<n;++i)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
}
bool judge(int ch)
{
	int sum=1;
	for (int i=0;i<len;++i)
	{
		if (height[i]<ch)sum=1;
		else sum++;
		if (sum==step)return true;
	}
	return false;
}
void height_get(int n)
{
	int k=0;
	for (int i=0;i<n;++i)rank[sa[i]]=i;
	for (int i=0;i<n;++i)
	{
		if (k)k--;
		if (rank[i])
		{
			int j=sa[rank[i]-1];
			while (num[i+k]==num[j+k])k++;
			height[rank[i]]=k;
		}
	}
	int l=0,r=n;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (judge(mid)){ans=mid;l=mid+1;}
		else r=mid-1;
	}
}
int main ()
{
	scanf ("%d%d",&len,&step);
	for (int b=0;b<len;++b)scanf ("%d",&num[b]);
	num[len++]=0;
	sa_get(len,mnum);
	height_get(len);
	printf ("%d",ans);
	return 0;
}
