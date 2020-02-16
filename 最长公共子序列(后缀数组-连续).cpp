#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
char s[100005];
int num[200005];
int len,le1,le2;
int a1[200005],a2[200005],js[200005];
int sa[200005],height[200005],ans,rank[200005];;
bool cmp(int *r,int i,int j,int l)
{
	return (r[i]==r[j] && r[i+l]==r[j+l]);
}
void sa_get(int n,int m)
{
	int *x=a1,*y=a2,*t,i,j,p;
	for (i=0;i<n;++i)js[x[i]=num[i]]++;
	for (i=1;i<m;++i)js[i]+=js[i-1];
	for (i=n-1;i>=0;--i)sa[--js[x[i]]]=i;
	for (j=1,p=1;p<n;j*=2,m=p)
	{
		for (p=0,i=n-j;i<n;++i)y[p++]=i;
		for (i=0;i<n;++i)if (sa[i]>=j)y[p++]=sa[i]-j;
		for (i=0;i<m;++i)js[i]=0;
		for (i=0;i<n;++i)js[x[y[i]]]++;
		for (i=1;i<m;++i)js[i]+=js[i-1];
		for (i=n-1;i>=0;--i)sa[--js[x[y[i]]]]=y[i];
		for (t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;++i)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
}
void height_get(int n)
{
	int k=0;
	for (int i=0;i<n;++i)rank[sa[i]]=i;
	for (int i=0;i<n;++i)
	{
		if (k)k--;
		int j=sa[rank[i]-1];
		while (num[i+k]==num[j+k])k++;
		height[rank[i]]=k;
		if ((sa[rank[i]]<le1 && sa[rank[i]-1]>le1) ||
			(sa[rank[i]]>le1 && sa[rank[i]-1]<le1))
		{	
			int u=k;
			if (k==len-sa[rank[i]] || k==len-sa[rank[i]-1])u--;
			ans=ans>u?ans:u;
		}
	}
}
int main ()
{
	scanf ("%s",s);le1=strlen(s);
	for (int b=0;b<le1;++b)num[len++]=s[b]-'a'+1;
	num[len++]=0;
	scanf ("%s",s);le2=strlen(s);
	for (int b=0;b<le2;++b)num[len++]=s[b]-'a'+1;
	num[len++]=0;
	sa_get(len,128);
	height_get(len);
//	cout <<len<<"  "<<le1<<"  "<<le2<<endl;
//	for (int b=0;b<len;++b)cout <<sa[b]<<"  ";cout <<endl;
//	for (int b=0;b<len;++b)cout <<height[b]<<"  ";cout <<endl;
	printf ("%d",ans);
	return 0;
}
