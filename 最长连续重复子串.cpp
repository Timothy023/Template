#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
const int N=100050;
const int M=25;
int a1[N],a2[N],ss[N],maxn,flag,cnt,ans[N],be,cas;
int num[N],sa[N],height[N],st[N][M+5],len,rank[N];
int bin[M+5],Log[N+5];
char ch[N];
inline bool cmp(int *r,int i,int j,int l){
	return (r[i]==r[j] && r[i+l]==r[j+l]);
}
inline void get_sa(int *r,int n,int m){
	int *x=a1,*y=a2,*t,i,j,p;
	for (i=0;i<m;++i)ss[i]=0;
	for (i=0;i<n;++i)ss[x[i]=r[i]]++;
	for (i=1;i<m;++i)ss[i]+=ss[i-1];
	for (i=n-1;i>=0;--i)sa[--ss[x[i]]]=i;
	for (j=1,p=1;p<n;j<<=1,m=p){
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
inline void get_height(int n){
	int k=0,i,j;
	for (i=1;i<=n;++i)rank[sa[i]]=i;
	for (i=0;i<n;height[rank[i++]]=k)
		for (k?k--:0,j=sa[rank[i]-1];num[i+k]==num[j+k];++k);
}
inline void get_st(int n){
	int i,j;
	for (i=1;i<=n;++i)st[i][0]=height[i];
	for (j=1;j<=M;++j)
		for (i=1;i<=n;++i)
			if (i+bin[j-1]<=n)
				st[i][j]=min(st[i][j-1],st[i+bin[j-1]][j-1]);
			else break;
}
inline int query(int x,int y){
	x=rank[x],y=rank[y];
	if (x>y)x^=y^=x^=y;
	++x;int m=Log[y-x+1];
	return min(st[x][m],st[y-bin[m]+1][m]);
}
int main (){
	bin[0]=1;for (int i=1;i<=M;++i)bin[i]=bin[i-1]<<1;
	Log[0]=-1;for (int i=1;i<=N-50;++i)Log[i]=Log[(i/2)]+1;Log[0]=0;
	while (scanf ("%s",ch) && ch[0]!='#'){
		len=strlen(ch);cnt=maxn=0;
		for (int i=0;i<len;++i)num[i]=(int)ch[i];
		num[len++]=0;
		get_sa(num,len,300);
		len--;
		get_height(len);
		get_st(len);
		for (int l=1;l<len;++l)
			for (int i=0;i+l<len;i+=l){
				int r=query(i,i+l);
				int su=r/l+1;
				int k=i-(l-r%l);
				if (k>=0&&r%l)
					if (query(k,k+l)>=r)
						su++;
				if (su>maxn){
					maxn=su;
					cnt=0;
					ans[cnt++]=l;
				}
				else if (su==maxn)
					ans[cnt++]=l;
			}
		flag=-1;
		for (int i=1;i<=len && flag==-1;++i)
			for (int j=0;j<cnt;++j){
				int l=ans[j];
				if (sa[i]+l<len && query(sa[i],sa[i]+l)>=(maxn-1)*l){
					flag=l;
					be=sa[i];
					break;
				}
			}
		printf ("Case %d: ",++cas);
		for (int i=be,j=0;j<maxn*flag;++j,++i)printf ("%c",ch[i]);
		puts("");
	}
	return 0;
}
