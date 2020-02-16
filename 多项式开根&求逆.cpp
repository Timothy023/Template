#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int I(){
	int s=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
const int mod=998244353;
const int N=5e5+5;
const int g=3;
int t1[N],t2[N],t3[N],t4[N];
int mi,x,l,n,m,a[N],b[N],c[N],d[N],ls[N],rev[N];
int ksm(int i,int j){
	int sum=1;
	while (j){
		if (j & 1)
			sum=1ll*sum*i%mod;
		i=1ll*i*i%mod;
		j>>=1;
	}
	return sum;
}
void NTT(int len,int *y,int f){
	mi=0;l=1;
	for (;l<len;l<<=1,mi++);
	for (int i=0;i<l;++i)rev[i]=((rev[i>>1]>>1)|((i&1)<<(mi-1)));
	for (int i=0;i<l;++i)
		if (i<rev[i])swap(y[i],y[rev[i]]);
	for (int i=1;i<l;i<<=1){
		int wn=ksm(g,(mod-1)/(i<<1)),f0,f1;
		if (f==-1)wn=ksm(wn,mod-2);
		for (int k=0;k<l;k+=(i<<1)){
			int w=1;
			for (int j=k;j<i+k;++j,w=1ll*w*wn%mod){
				f0=y[j];f1=1ll*y[i+j]*w%mod;
				y[j]=(f0+f1)%mod;y[i+j]=(f0-f1+mod)%mod;
			}
		}
	}
	if (f==-1){
		int tmp=ksm(l,mod-2);
		for (int i=0;i<l;++i)y[i]=1ll*y[i]*tmp%mod;
	}
}
void solve(int len,int *y,int *b){
	if (len==1)return (void)(b[0]=ksm(y[0],mod-2),b[1]=0);
	solve(len>>1,y,b);
	for (int i=0;i<len;++i)ls[i]=y[i];
	for (int i=len;i<len*2;++i)ls[i]=0;
	for (int i=len;i<len*2;++i)b[i]=0;
	NTT(len*2,ls,1);NTT(len*2,b,1);
	for (int i=0;i<len*2;++i)
		b[i]=(2*b[i]%mod-1ll*b[i]*b[i]%mod*ls[i]%mod+mod)%mod;
	NTT(len*2,b,-1);
	for (int i=len;i<len*2;++i)b[i]=0;
}
void get_ny(int l,int *y,int *b){
	int len=1;
	while (len<l)len<<=1;
	solve(len,y,b);
}
void sqr(int len,int *y,int *b){
	if (len==1)return (void)(b[0]=1,b[1]=0);
	sqr(len>>1,y,b);
	for (int i=len;i<len*2;++i)b[i]=0;
	NTT(len*2,b,1);
	for (int i=0;i<len*2;++i){
		t1[i]=b[i]*2%mod;
		t2[i]=1ll*b[i]*b[i]%mod;
	}
	NTT(len*2,t1,-1);
	for (int i=0;i<len*2;++i)t4[i]=0;
	get_ny(len,t1,t4);
	for (int i=0;i<len;++i)t3[i]=y[i];
	for (int i=len;i<len*2;++i)t3[i]=0;
	NTT(len*2,t3,1);NTT(len*2,t4,1);
	for (int i=0;i<len*2;++i)
		b[i]=1ll*(t3[i]+t2[i])*t4[i]%mod;
	NTT(len*2,b,-1);
	for (int i=len;i<len*2;++i)b[i]=0;
}
void get_sqr(int l,int *y,int *b){
	int len=1;
	while (len<l)len<<=1;
	sqr(len,y,b);
}
int main (){
	n=I();m=I();c[0]=1;
	for (int i=0;i<n;++i){
		x=I();a[x]+=2;c[x]=(c[x]-4+mod)%mod;
	}
	get_sqr(m+1,c,d);d[0]=(d[0]+1)%mod;
	for (int i=m+1;i<N;++i)d[i]=0;
	get_ny(m+1,d,b);
	for (int i=1;i<=m;++i)
		printf ("%d\n",b[i]*2%mod);
	return 0;
}
