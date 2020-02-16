#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=20005;
struct node{
	double x,y;
	node(){}
	node(double _x,double _y){x=_x;y=_y;}
	friend node operator + (node i,node j){
		return node(i.x+j.x,i.y+j.y);
	}
	friend node operator - (node i,node j){
		return node(i.x-j.x,i.y-j.y);
	}
	friend node operator * (node i,double j){
		return node(i.x*j,i.y*j);
	}
	friend double operator * (node i,node j){
		return (i.x*j.y-i.y*j.x);
	}
}q[N];
struct line{
	node st,en;
	double slop;
	friend bool operator < (line i,line j){
		if (i.slop!=j.slop)return i.slop<j.slop;
		else return (j.en-i.st)*(j.st-i.st)>0;
	}
}p[N],st[N];
int n,tot,L,R;
double ans=0;
inline node get_jiao(line i,line j){
	double t=((j.en-j.st)*(i.st-j.st))/((i.en-i.st)*(j.en-j.st));
	return (i.st+(i.en-i.st)*t);
}
inline bool judge(line i,line j,line k){
	node t=get_jiao(i,j);
	return (k.st-t)*(k.en-t)<0;
}
inline void bpmj(){
	tot=0;
	for (int i=1;i<=n;++i){
		if (p[i-1].slop!=p[i].slop)tot++;
		p[tot]=p[i];
	}
	L=1,R=2;st[1]=p[1];st[2]=p[2];
	for (int i=3;i<=tot;++i){
		while (L<R && judge(st[R],st[R-1],p[i]))R--;
		while (L<R && judge(st[L],st[L+1],p[i]))L++;
		st[++R]=p[i];
	}
	while (L<R && judge(st[R],st[R-1],st[L]))R--;
	while (L<R && judge(st[L],st[L+1],st[R]))L++;
	tot=0;st[R+1]=st[L];
	for (int i=L;i<=R;++i)
		q[++tot]=get_jiao(st[i],st[i+1]);
}
inline void solve(){
	if (tot<3)return;
	q[++tot]=q[1];
	for (int i=1;i<=tot;++i)
		ans+=q[i]*q[i+1];
}
int main (){
	scanf ("%d",&n);
	for (int i=1;i<=n;++i)
		scanf ("%lf%lf%lf%lf",&p[i].st.x,&p[i].st.y,&p[i].en.x,&p[i].en.y);
	p[++n].st=node(0,0);p[n].en=node(10000,0);
	p[++n].st=node(10000,0);p[n].en=node(10000,10000);
	p[++n].st=node(10000,10000);p[n].en=node(0,10000);
	p[++n].st=node(0,10000);p[n].en=node(0,0);
	for (int i=1;i<=n;++i)
		p[i].slop=atan2(p[i].en.y-p[i].st.y,p[i].en.x-p[i].st.x);
	sort(p+1,p+n+1);
	bpmj();solve();
	printf ("%.1lf",fabs(ans)/2.0);
	return 0;
}
