#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=10005;
char s[N];
int len;
inline int get_min(){
	int i=0,j=1,k=0,t;
	while (i<len && j<len && k<len){
		t=s[(i+k>=len)?(i+k-len):i+k]-s[(j+k>=len)?(j+k-len):j+k];
		if (!t)++k;
		else{
			if (t>0)i=i+k+1;
			else j=j+k+1;
			if (i==j)j++;
			k=0;
		}
	}
	return (i<j?i:j)+1;
}
int main (){
	scanf ("%s",s);
	len=strlen(s);
	printf ("%d",get_min());
	return 0;
}
