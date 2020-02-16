#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#define INF 2147483647
#define key_value ch[ch[root][1]][0]
using namespace std;
int n,m,a[100005],ch[200005][2],num[200005],add[200005],Min[200005],sum[200005];
int fa[200005],sz,root;
bool flag[200005];
inline int min(int a1,int a2)
{
    return a1>a2?a2:a1;
}
inline void pushup(int ro)
{
	sum[ro]=sum[ch[ro][0]]+sum[ch[ro][1]]+1;
	Min[ro]=min(num[ro],min(Min[ch[ro][0]],Min[ch[ro][1]]));
}
inline void pushdown(int ro)
{
//    cout <<num[ro]<<"  "<<add[ro]<<endl;system ("pause");
	if (flag[ro])
	{
		int t=ch[ro][0];
		ch[ro][0]=ch[ro][1];
		ch[ro][1]=t;
		flag[ch[ro][0]]^=1;
		flag[ch[ro][1]]^=1;
		flag[ro]=0;
	}
	if (add[ro])
	{
        if (ch[ro][0])
        {
            num[ch[ro][0]]+=add[ro];
            Min[ch[ro][0]]+=add[ro];
            add[ch[ro][0]]+=add[ro];
        }
        if (ch[ro][1])
        {
            add[ch[ro][1]]+=add[ro];
            num[ch[ro][1]]+=add[ro];
            Min[ch[ro][1]]+=add[ro];
        }
        add[ro]=0;
    }
}
/*
void print(int ro)
{
//	cout <<Min[ro]<<"  "<<num[ro]<<"  "<<num[ch[ro][0]]<<"  "<<num[ch[ro][1]]<<endl;system ("pause");
	if (!ro)return;
	pushdown(ro);
	print(ch[ro][0]);
//	if (num[ro]>=1 && num[ro]<=n)printf("%d ",num[ro]);
	print(ch[ro][1]);
}
*/
inline void NewNode(int &ro,int f,int key)
{
	ro=++sz;
	fa[ro]=f;
	num[ro]=Min[ro]=key;
	sum[ro]=1;
}
inline void build(int l,int r,int &ro,int f)
{
//	cout <<l<<"  "<<r<<"  "<<num[f]<<endl;system ("pause");
	if (l>r)return;
	int mid=(l+r)>>1;
	NewNode(ro,f,a[mid]);
	build(l,mid-1,ch[ro][0],ro);
	build(mid+1,r,ch[ro][1],ro);
	pushup(ro);
}
inline int query(int ro,int x)
{
	pushdown(ro);
	if (sum[ch[ro][0]]+1==x)return ro;
	else if (sum[ch[ro][0]]+1>x)return query(ch[ro][0],x);
	else return query(ch[ro][1],x-sum[ch[ro][0]]-1);
}
inline void Rotate(int x,int kind)
{
	int y=fa[x];
//	pushdown(y);
//	pushdown(x);
	ch[y][!kind]=ch[x][kind];
	fa[ch[x][kind]]=y;
	if (fa[y])ch[fa[y]][ch[fa[y]][1]==y]=x;
	fa[x]=fa[y];
	ch[x][kind]=y;
	fa[y]=x;
	pushup(y);
}
inline void splay(int r,int goal)
{
//	pushdown(r);
	while (fa[r]!=goal)
	{
		if (fa[fa[r]]==goal)
		{
//			pushdown(fa[r]);
//			pushdown(r);
			Rotate(r,ch[fa[r]][0]==r);
		}
		else
		{
//			pushdown(fa[fa[r]]);
//			pushdown(fa[r]);
//			pushdown(r);
			int y=fa[r];
			int kind=(ch[fa[y]][0]==y);
			if (ch[y][kind]==r)
			{
				Rotate(r,!kind);
				Rotate(r,kind);
			}
			else
			{
				Rotate(y,kind);
				Rotate(r,kind);
			}
		}
	}
	pushup(r);
	if (goal==0)root=r;
}
int main ()
{
	scanf ("%d",&n);
	Min[0]=INF;
	NewNode(root,0,INF);
	NewNode(ch[root][1],root,INF);
    for (int b=1;b<=n;++b)scanf ("%d",&a[b]);
	build(1,n,key_value,ch[root][1]);
	pushup(ch[root][1]);pushup(root);
//	print(root);cout <<endl;
	scanf ("%d",&m);
	for (int b=1;b<=m;++b)
	{
        string CH;int i,j,k;
        cin >>CH;
        if (CH=="ADD")
        {
            scanf ("%d%d%d",&i,&j,&k);
            splay(query(root,i),0);
            splay(query(root,j+2),root);
            num[key_value]+=k;
            add[key_value]+=k;
            Min[key_value]+=k;
            pushup(ch[root][1]);
            pushup(root);
        }
		else if (CH=="REVERSE")
        {
            scanf ("%d%d",&i,&j);
            splay(query(root,i),0);
            splay(query(root,j+2),root);
            flag[key_value]^=1;
            pushup(ch[root][1]);
            pushup(root);
        }
		else if (CH=="REVOLVE")
        {
            scanf ("%d%d%d",&i,&j,&k);
            k%=(j-i+1);
            if (k<0)k+=j-i+1;
            k%=(j-i+1);
            splay(query(root,j-k+1),0);
            splay(query(root,j+2),root);
            int u=key_value;
            key_value=0;
            pushup(ch[root][1]);
            pushup(root);
            splay(query(root,i),0);
            splay(query(root,i+1),root);
            key_value=u;
            fa[key_value]=ch[root][1];
            pushup(ch[root][1]);
            pushup(root);
        }
		else if (CH=="INSERT")
        {
            scanf ("%d%d",&i,&j);
            splay(query(root,i+1),0);
            splay(query(root,i+2),root);
            NewNode(key_value,ch[root][1],j);
            pushup(ch[root][1]);
            pushup(root);
        }
		else if (CH=="DELETE")
        {
            scanf ("%d",&i);
            splay(query(root,i),0);
            splay(query(root,i+2),root);
            fa[key_value]=0;key_value=0;
            pushup(ch[root][1]);
            pushup(root);
        }
        else if (CH=="MIN")
        {
            scanf ("%d%d",&i,&j);
            splay(query(root,i),0);
            splay(query(root,j+2),root);
//            print(root);cout <<endl;
            printf ("%d\n",Min[key_value]);
        }
    }
	return 0;
}
/*
5
1 
2 
3 
4 
5
2
ADD 2 4 1
MIN 4 5
*/







