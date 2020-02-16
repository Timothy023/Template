#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
const int N=200005;
const int root=1;
char s[N];
int ans,n;
int fa[N],len[N],ch[N][26],cnt,now,p,q,last,cop;
int val[N],sum[N],t[N],ls[N];
inline void insert(int x){
	now=++cnt;len[cnt]=len[last]+1;p=last;
	for (;p && !ch[p][x];p=fa[p])ch[p][x]=now;
	if (!p)fa[now]=root;
	else{
		q=ch[p][x];
		if (len[p]+1==len[q])fa[now]=q;
		else{
			cop=++cnt;
			len[cop]=len[p]+1;
			memcpy(ch[cop],ch[q],sizeof(ch[q]));
			fa[cop]=fa[q];
			fa[now]=fa[q]=cop;
			for (;ch[p][x]==q;p=fa[p])ch[p][x]=cop;
		}
	}
	last=now;
}
inline bool solve(){
	if (scanf ("%s",s+1)==EOF)return 0;
	memset(ls,0,sizeof(ls));
	n=strlen(s+1);
	for (int i=1,tmp=0,wz=root,x;i<=n;++i){
		x=s[i]-'a';
		if (ch[wz][x])wz=ch[wz][x],tmp++;
		else{
			while (wz && !ch[wz][x])wz=fa[wz];
			if (!wz)wz=root,tmp=0;
			else {
				tmp=len[wz]+1;
				wz=ch[wz][x];
			}
		}
		ls[wz]=max(ls[wz],tmp);
	}
	for (int i=cnt;i>=1;--i){
		val[t[i]]=min(val[t[i]],ls[t[i]]);
		if (ls[t[i]] && fa[t[i]])ls[fa[t[i]]]=len[fa[t[i]]];
	}
	return 1;
}
int main (){
	last=++cnt;
	scanf ("%s",s+1);n=strlen(s+1);
	for (int i=1;i<=n;++i)insert(s[i]-'a');
	for (int i=1;i<=cnt;++i){
		val[i]=len[i];
		sum[len[i]]++;
	}
	for (int i=1;i<=n;++i)sum[i]+=sum[i-1];
	for (int i=cnt;i>=1;--i)t[sum[len[i]]--]=i;
	while (solve());
	for (int i=1;i<=cnt;++i)
		ans=max(ans,val[i]);
	printf ("%d",ans);
	return 0;
}
