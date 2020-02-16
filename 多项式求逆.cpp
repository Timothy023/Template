#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int I(){
	int s=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
const int g=3;
const int N=5e5+5;
const int mod=998244353;
int n,a[N],b[N],c[N],lim,rev[N],l,mi;
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
void pre_rev(int lim){
	for (l=1,mi=0;l<=lim;l<<=1,mi++);
	for (int i=0;i<l;++i)rev[i]=((rev[i>>1]>>1)|((i&1)<<(mi-1)));
}
void NTT(int *y,int f){
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
void solve(int len){
	if (len==1)return (void)(b[0]=ksm(a[0],mod-2));
	solve(len/2);
	pre_rev(len);
	for (int i=0;i<len;++i)c[i]=a[i];
	for (int i=len;i<l;++i)c[i]=0;
	NTT(b,1);NTT(c,1);
	for (int i=0;i<l;++i)
		b[i]=(2*b[i]%mod-1ll*b[i]*b[i]%mod*c[i]%mod+mod)%mod;
	NTT(b,-1);
	for (int i=len;i<l;++i)b[i]=0;
}
int main (){
	n=I();
	for (int i=0;i<n;++i)a[i]=I();
	for (lim=1;lim<n;lim<<=1);
	solve(lim);
	for (int i=0;i<n;++i)printf ("%d ",b[i]);
	return 0;
}
