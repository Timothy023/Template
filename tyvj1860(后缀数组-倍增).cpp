#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#define maxn 200005
using namespace std;
int a1[maxn],a2[maxn],ss[maxn];
bool cmp(int *r,int i,int j,int len)
{
    return (r[i]==r[j] && r[i+len]==r[j+len]);
	//判断两个字符串时候完全一样 
	//即前缀和后缀是否一样 
}
void sa_get(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=a1,*y=a2,*t;//使用指针在后面交换的时候直接交换指针
    //x[i]相当于rank数组，表示第i个排第几 
    for (i=0;i<m;++i)ss[i]=0;
    for (i=0;i<n;++i)ss[x[i]=r[i]]++;
    for (i=1;i<m;++i)ss[i]+=ss[i-1];
    for (i=n-1;i>=0;--i)sa[--ss[x[i]]]=i;
	//对后缀进行排序(刚开始时只有一个字符) 
	//桶排不会改变元素的相对位置 
    for (j=1,p=1;p<n;j*=2,m=p)
    {
        for (p=0,i=n-j;i<n;++i)y[p++]=i;//后面j个的后缀为0，一定最小 
        for (i=0;i<=n;++i)if (sa[i]>=j)y[p++]=sa[i]-j;
		//按照后缀从小到大的顺序排列前缀 
		//先确定后缀的顺序
        for (i=0;i<m;++i)ss[i]=0;
        for (i=0;i<n;++i)ss[x[y[i]]]++;
        for (i=1;i<m;++i)ss[i]+=ss[i-1];
        for (i=n-1;i>=0;--i)sa[--ss[x[y[i]]]]=y[i];//对前缀进行排序 
        for (t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;++i)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;//更新x的值 
    }
    return;
}
char s[maxn];
int sa[maxn],sum,num[maxn];
int height[maxn],rank[maxn];
void height_get(int *r,int n)
{
    int k=0;
    for (int i=0;i<n;++i)rank[sa[i]]=i;
    for (int i=0;i<n;++i)
    {
        if (k)k--;
        int j=sa[rank[i]-1];
        while (r[i+k]==r[j+k])k++;
        height[rank[i]]=k;
    }
}//求最长公共前缀,利用h[i]>=h[i-1]-1 
int main ()
{
    scanf ("%s",s);
    sum=strlen(s);
    for (int b=0;b<sum;++b)num[b]=s[b]-'a'+1;
    num[sum++]=0;
    sa_get(num,sa,sum,128);
    height_get(num,sum);
    for (int b=1;b<sum;++b)printf ("%d ",sa[b]+1);puts("");
    for (int b=1;b<sum;++b)printf ("%d ",height[b]);puts("");
    return 0;
}
