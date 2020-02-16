#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const long long Mod=998244353;
inline void read(int &s)
{
	s=0;int f=1;char ch=getchar();
	while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){s=s*10+ch-'0';ch=getchar();}
	s*=f;
}
int fa[500005],sum[500005],deep[500005],poi1[500005],poi2[500005],pof[500005];
int n,m,len;
long long ans1[500005],ans2[500005];
int i[500005],j[500005];
long long ny[500005];
int pre(int x)
{
	if (fa[x]!=x)return pre(fa[x]);
	return fa[x];
}
inline long long mi(int u,int v)
{
	long long sum=1;
	while (v)
	{
		if (v & 1)
			sum=sum*u%Mod;
		u=(long long)u*u%Mod;
		v>>=1;
	}
	return sum;
}
int main ()
{
	freopen ("point.in","r",stdin);
	freopen ("point.out","w",stdout);
	read(n);read(m);
	for (int b=1;b<=n;++b)
	{
		fa[b]=b;
		sum[b]=1;
		deep[b]=1;
		ny[b]=mi(b,Mod-2);
	}
	ans1[len]=n;ans2[len]=1;
	for (int b=1;b<=m;++b)
	{
		int k;
		read(k);
		if (k==1)
		{
			len++;
			read(i[len]);read(j[len]);
			int t1=pre(i[len]),t2=pre(j[len]);
			ans1[len]=ans1[len-1];
			ans2[len]=ans2[len-1];
			if (t1==t2)
			{
				pof[len]=2;
				printf ("%I64d %I64d\n",ans1[len],ans2[len]);
				continue;
			}
			ans1[len]--;
			ans2[len]=((ans2[len]*(ny[sum[t1]]*ny[sum[t2]]%Mod)%Mod)*((long long)sum[t1]+sum[t2]))%Mod;
			//----------------------------------------------
			if (deep[t1]>=deep[t2])
			{
				fa[t2]=t1;
				sum[t1]+=sum[t2];
				if (deep[t1]==deep[t2])
				{
					pof[len]=1;
					deep[t1]++;
				}
				else pof[len]=0;
				poi1[len]=t2;
				poi2[len]=t1;
			}
			else
			{
				fa[t1]=t2;
				sum[t2]+=sum[t1];
				poi1[len]=t1;
				poi2[len]=t2;
				pof[len]=0;
			}
			//------------------------------------------------
		}
		else
		{
			int w;
			read(w);
			for (;len && w;--len,--w)
			{
				if (pof[len]==2)continue;
				fa[poi1[len]]=poi1[len];
				if (pof[len])deep[poi2[len]]--;
				sum[poi2[len]]-=sum[poi1[len]];
			}
		}
		printf ("%I64d %I64d\n",ans1[len],ans2[len]);
	}
	return 0;
}
