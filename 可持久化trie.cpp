#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=2000005;
char a[N],s[N],s1[N],s2[N];
int n,ls,len,m,l1,l2,ans;
int ch[N][27],ri[N],le[N],cnt;
int root[N];
struct node{
	int st,en;
	friend bool operator < (node i,node j){
		int li=i.en-i.st+1,lj=j.en-j.st+1;
		for (int k=0;k<li && k<lj;++k)
			if (s[i.st+k]>s[j.st+k])return 0;
			else if (s[i.st+k]<s[j.st+k])return 1;
		return li<lj;
	}
}zfc[N];
struct cjh{int sum,ne[27];}tr[N];
inline void trie(){
	int now,x;
	for (int i=1;i<=n;++i){
		now=0;
		for (int j=zfc[i].st;j<=zfc[i].en;++j){
			x=s[j]-'a';
			if (!ch[now][x])
				ch[now][x]=++cnt;
			now=ch[now][x];
			if (!le[now])le[now]=i;
			ri[now]=i;
		}
	}
}
void insert(int &ro,int l,int r){
	tr[++cnt]=tr[ro];++tr[cnt].sum;ro=cnt;
	if (l>r)return;
	int x=s[r]-'a';
	insert(tr[ro].ne[x],l,r-1);
}
int query(int r1,int r2,int sz){
	if (sz<0)return tr[r2].sum-tr[r1].sum;
	int x=s2[sz]-'a';
	query(tr[r1].ne[x],tr[r2].ne[x],sz-1);
	
}
int main (){
	scanf ("%d",&n);
	for (int i=1;i<=n;++i){
		scanf ("%s",a);
		ls=strlen(a);
		zfc[i].st=len;
		for (int j=0;j<ls;++j)s[len++]=a[j];
		zfc[i].en=len-1;
	}
	sort(zfc+1,zfc+n+1);
	trie();
	cnt=0;
	for (int i=1;i<=n;++i){
		root[i]=root[i-1];
		insert(root[i],zfc[i].st,zfc[i].en);
	}
	scanf ("%d",&m);
	int now,x,l,r;
	for (int i=1;i<=m;++i){
		scanf ("%s",s1);l1=strlen(s1);
		scanf ("%s",s2);l2=strlen(s2);
		for (int j=0;j<l1;++j)s1[j]=(s1[j]-'a'+ans)%26+'a';
		for (int j=0;j<l2;++j)s2[j]=(s2[j]-'a'+ans)%26+'a';
		now=0,l=-1,r=-1;
		for (int j=0;j<l1;++j){
			x=s1[j]-'a';
			if (!ch[now][x])break;
			now=ch[now][x];
			if (j==l1-1)l=le[now],r=ri[now];
		}
		if (l==-1 && r==-1)ans=0;
		else ans=query(root[l-1],root[r],l2-1);
		printf ("%d\n",ans);
	}
	return 0;
}
