#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int A,n,mod;
long long f[2005][515];
long long x[2005],y[2005],len;
long long jc[505]={1};
long long ksm(long long i,long long j)
{
	long long sum=1;
	while (j)
	{
		if (j & 1)
			sum=sum*i%mod;
		i=i*i%mod;
		j>>=1;
	}
	return sum;
}
long long lagerange()
{
	long long s=1,ans=0;
	for (int i=1;i<=len;++i)s=s*(A-x[i]+mod)%mod;
	for (int i=1;i<=len;++i)
	{
		long long tmp=(A-x[i]+mod)%mod;
		for (int j=1;j<=len;++j)
			if (i!=j)tmp=tmp*(x[i]-x[j]+mod)%mod;
		ans=(ans+s*ksm(tmp,mod-2)%mod*y[i])%mod;
	}
	return ans;
}
int main ()
{
	scanf ("%d%d%d",&A,&n,&mod);
	for (int i=1;i<=n;++i)jc[i]=jc[i-1]*i%mod;
	f[0][0]=1;
	for (int i=1;i<=3*n+5;++i)
	{
		f[i][0]=1;
		for (int j=1;j<=n+5;++j)
			f[i][j]=(f[i-1][j]+f[i-1][j-1]*i%mod)%mod;
	}
	for (int i=1;len<=2*n+1;++i)
		if (i!=A && f[i][n])
		{
			x[++len]=i;
			y[len]=f[i][n];
		}
	cout <<lagerange()*jc[n]%mod;
	return 0;
}
