#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=500005;
const int root=1;
char s[N];
int l,len[N],ch[N][28],f[N],fa[N];
int last,cnt,p,np,q,nq;
int r[N],sum[N],t[N];
inline void insert(int x){
	np=++cnt;len[np]=len[last]+1;p=last;
	for (;p && !ch[p][x];p=fa[p])ch[p][x]=np;
	if (!p)fa[np]=root;
	else{
		q=ch[p][x];
		if (len[q]==len[p]+1)fa[np]=q;
		else{
			nq=++cnt;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			len[nq]=len[p]+1;
			fa[nq]=fa[q];
			for (;ch[p][x]==q;p=fa[p])ch[p][x]=nq;
			fa[q]=fa[np]=nq;
		}
	}
	last=np;
}
int main (){
	scanf ("%s",s+1);
	l=strlen(s+1);last=++cnt;
	for (int i=1;i<=l;++i)
		insert(s[i]-'a');
	for (int i=1,j=root;i<=l;++i){
		j=ch[j][s[i]-'a'];
		r[j]++;
	}
	for (int i=1;i<=cnt;++i)sum[len[i]]++;
	for (int i=1;i<=l;++i)sum[i]+=sum[i-1];
	for (int i=1;i<=cnt;++i)t[sum[len[i]]--]=i;
	for (int i=cnt;i>0;--i)r[fa[t[i]]]+=r[t[i]];//«Ûright÷µ 
	for (int i=1;i<=cnt;++i)f[len[i]]=max(f[len[i]],r[i]);
	for (int i=l;i>0;--i)f[i]=max(f[i],f[i+1]);
	for (int i=1;i<=l;++i)printf ("%d\n",f[i]);
	return 0;
}
