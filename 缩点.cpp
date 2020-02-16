#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
using namespace std;
int po[10005],n,len,i,so,si,Out[10005],In[10005];
vector < int > son[10005];
int dfn[10005],low[10005],step,sta[10005],top;
bool flag[10005];
//------------------------------------------------
void dfs(int ro)
{
	low[ro]=dfn[ro]=++step;
	sta[++top]=ro;
	flag[ro]=1;
	for (int b=0;b<son[ro].size();++b)
	{
		if (!dfn[son[ro][b]])
		{
			dfs(son[ro][b]);
			low[ro]=min(low[ro],low[son[ro][b]]);
		}
		else 
			if (flag[son[ro][b]])
				low[ro]=min(low[ro],dfn[son[ro][b]]);
	}
	if (dfn[ro]==low[ro])
	{
		int wz=top;
		++len;
		while (sta[wz]!=ro)
		{
			po[sta[wz]]=len;
			flag[sta[wz]]=0;
			wz--;
		}
		po[ro]=len;
		flag[ro]=0;
		top=wz-1;
	}
}
//------------------------------------------------
int main ()
{
	scanf ("%d",&n);
	for (int b=1;b<=n;++b)
		while (1)
		{
			scanf ("%d",&i);
			if (!i)break;
			son[b].push_back(i);
		}
	//------------------------------------------------
	for (int b=1;b<=n;++b)
		if (!dfn[b])
			dfs(b);
	for (int b=1;b<=n;++b)
		for (int c=0;c<son[b].size();++c)
			if (po[b]!=po[son[b][c]])
			{
				Out[po[b]]++;
				In[po[son[b][c]]]++;
			}
	//------------------------------------------------
	for (int b=1;b<=len;++b)
	{
		if (Out[b]==0)so++;
		if (In[b]==0)si++;
	}
	if (len==1)printf ("1\n0");
	else printf ("%d\n%d",si,max(so,si));
	return 0;
}
