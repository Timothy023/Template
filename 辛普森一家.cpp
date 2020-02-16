#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1005;
const double esp=2e-13;
int n,st,en;
double xl[N],xr[N],ans;
bool del[N];
struct node{
	double x,y,r;
}t[N],sk[N];
struct orz{
	double l,r;
}p[N];
double dis(node i,node j){
	return sqrt((i.x-j.x)*(i.x-j.x)+(i.y-j.y)*(i.y-j.y));
}
bool cmp1(node i,node j){
	return i.r<j.r;
}
bool cmp2(node i,node j){
	return i.x-i.r<j.x-j.r;
}
bool cmp3(orz i,orz j){
	return i.l<j.l;
}
double get(double x){
	int sz=0;double r,len=0,dis;
	for (int i=st;i<=en;++i){
		if (x<=xl[i] || x>=xr[i])continue;
		dis=sqrt(sk[i].r-(x-sk[i].x)*(x-sk[i].x));
		p[++sz].l=sk[i].y-dis;p[sz].r=sk[i].y+dis;
	}
	sort(p+1,p+sz+1,cmp3);
	for (int i=1,j;i<=sz;++i){
		r=p[i].r;
		for (j=i+1;j<=sz;++j){
			if (p[j].l>r)break;
			r=max(r,p[j].r);
		}
		len+=r-p[i].l;
		i=j-1;
	}
	return len;
}
double calc(double l,double fl,double fmid,double fr){
	return (fl+fr+fmid*4)*l/6;
}
double simpson(double l,double mid,double r,double fl,double fmid,double fr,double s){
	double m1=(l+mid)/2,m2=(r+mid)/2;
	double f1=get(m1),f2=get(m2);
	double g1=calc(mid-l,fl,f1,fmid),g2=calc(r-mid,fmid,f2,fr);
	if (fabs(g1+g2-s)<esp)return g1+g2;
	return simpson(l,m1,mid,fl,f1,fmid,g1)+simpson(mid,m2,r,fmid,f2,fr,g2);
}
int main (){
	scanf ("%d",&n);
	for (int i=1;i<=n;++i)
		scanf ("%lf%lf%lf",&t[i].x,&t[i].y,&t[i].r);
	sort(t+1,t+n+1,cmp1);
	for (int i=1;i<=n;++i)
		for (int j=i+1;j<=n;++j)
			if (dis(t[i],t[j])<=t[j].r-t[i].r){
				del[i]=1;break;
			}
	int ls=n;n=0;
	for (int i=1;i<=ls;++i)
		if (!del[i])sk[++n]=t[i];
	sort(sk+1,sk+n+1,cmp2);
	double l,r,mid,fl,fr,fmid;
	for (int i=1;i<=n;++i){
		xl[i]=sk[i].x-sk[i].r;
		xr[i]=sk[i].x+sk[i].r;
		sk[i].r*=sk[i].r;
	}
	for (int i=1,j;i<=n;++i){
		l=xl[i];r=xr[i];
		for (j=i+1;j<=n;++j){
			if (xl[j]>r)break;
			r=max(r,xr[j]);
		}
		st=i;en=j-1;i=j-1;
		mid=(l+r)/2;
		fl=get(l);fr=get(r);fmid=get(mid);
		ans+=simpson(l,mid,r,fl,fmid,fr,calc(r-l,fl,fmid,fr));
	}
	printf ("%.3lf",ans);
	return 0;
}
