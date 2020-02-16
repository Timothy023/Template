#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=2000005;
const int M=2000000;
bool flag[N],vis[N];
long long phi[N],niu[N],pri[N],p[N],q[N];
int cas,len,n;
long long get_p(int x){
	return x<=M?phi[x]:p[n/x];
}
long long get_q(int x){
	return x<=M?niu[x]:q[n/x];
}
void solve(int x){
	if (x<=M)return;
	int i,j=1,t=n/x;
	if (vis[t])return;
	vis[t]=1;
	p[t]=((long long)x+1)*x>>1;
	q[t]=1;
	while (j<x){
		i=j+1;j=x/(x/i);solve(x/i);
		p[t]-=get_p(x/i)*(j-i+1);
		q[t]-=get_q(x/i)*(j-i+1);
	}
}
int main (){
	scanf ("%d",&cas);
	phi[1]=niu[1]=1;
	for (int i=2;i<=M;++i){
		if (!flag[i]){
			pri[++len]=i;
			phi[i]=i-1;
			niu[i]=-1;
		}
		for (int j=1;j<=len && pri[j]*i<=M;++j){
			flag[pri[j]*i]=1;
			if (i%pri[j]==0){
				phi[i*pri[j]]=phi[i]*pri[j];
				niu[pri[j]*i]=0;
				break;
			}
			phi[i*pri[j]]=phi[i]*phi[pri[j]];
			niu[pri[j]*i]=-niu[i];
		}
	}
	for (int i=2;i<=M;++i){
		phi[i]+=phi[i-1];
		niu[i]+=niu[i-1];
	}
	while (cas --> 0){
		scanf ("%d",&n);
		if (n<=M)printf("%lld %lld\n",phi[n],niu[n]);
		else{
			memset(vis,0,sizeof(vis));
			solve(n);
			printf ("%lld %lld\n",p[1],q[1]);
		}
	}
	return 0;
}
