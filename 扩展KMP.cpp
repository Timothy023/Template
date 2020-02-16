#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=1000005;
char s1[N],s2[N];
int l1,l2,next[N],ext[N],p,l,wz;
inline void get_next(){
	next[0]=l2;
	while (s2[p]==s2[p+1] && p+1<l2)p++;
	next[1]=p;wz=1;
	for (int i=2;i<l2;++i){
		if (next[i-wz]+i<next[wz]+wz)
			next[i]=next[i-wz];
		else {
			p=next[wz]+wz-i;
			p=p<0?0:p;
			while (i+p<l2 && s2[p]==s2[i+p])++p;
			next[i]=p;wz=i;
		}
	}
}
inline void get_ext(){
	p=0;
	while (s1[p]==s2[p] && p<l1 && p<l2)p++;
	ext[0]=p;wz=0;
	for (int i=1;i<l1;++i){
		if (next[i-wz]+i<ext[wz]+wz)
			ext[i]=next[i-wz];
		else {
			p=ext[wz]+wz-i;
			p=p<0?0:p;
			while (i+p<l1 && p<l2 && s2[p]==s1[i+p])++p;
			ext[i]=p;wz=i;
		}
	}
}
int main (){
	scanf ("%s%s",s1,s2);
	l1=strlen(s1);l2=strlen(s2);
	get_next();
	get_ext();
	for (int i=0;i<l2;++i)
		printf ("%d ",next[i]);
	puts("");
	for (int i=0;i<l1;++i)
		printf ("%d ",ext[i]);
	return 0;
}
