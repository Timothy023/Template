#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int mod=1e9;
int a[200][200],b[200][200];
int n,m,x,y,cnt,xh[20][20],mark;
long long c[200][200],ans,tmp;
char ch[10];
inline long long gauss(){
	for (int i=1;i<=cnt;++i){
		int j=i;
		for (;j<=cnt;++j)if (c[j][i])break;
		if (j>cnt)return 0;
		if (j!=i){swap(c[i],c[j]);mark^=1;}
		for (j=i+1;j<=cnt;++j)
			while (c[j][i]){
				tmp=c[j][i]/c[i][i];
				for (int k=i;k<=cnt;++k)
					c[j][k]=((c[j][k]-c[i][k]*tmp%mod)%mod+mod)%mod;
				if (!c[j][i])break;
				swap(c[i],c[j]);
				mark^=1;
			}
	}
	ans=1;
	for (int i=1;i<=cnt;++i)ans=(ans*c[i][i])%mod;
	if (mark)ans=(mod-ans)%mod;
	return ans;
}
int main (){
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf ("%s",ch+1);
		for (int j=1;j<=m;++j)
			if (ch[j]=='.'){
				y=xh[i][j]=++cnt;
				if (x=xh[i-1][j]){
					a[x][x]++;a[y][y]++;
					b[x][y]++;b[y][x]++;
				}
				if (x=xh[i][j-1]){
					
					a[x][x]++;a[y][y]++;
					b[x][y]++;b[y][x]++;
				}
			}
	}
	for (int i=1;i<=cnt;++i)
		for (int j=1;j<=cnt;++j)
			c[i][j]=((a[i][j]-b[i][j])%mod+mod)%mod;
	--cnt;
	printf ("%lld",gauss());
	return 0;
}
