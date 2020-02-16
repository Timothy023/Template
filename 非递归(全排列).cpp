#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,sta[15],len=1;
bool jc[15];
inline void dfs()
{
	while (len)
	{
		if (len>n)
		{
			for (int b=1;b<len;++b)
				printf ("%5d",sta[b]);
			puts("");len--;
		}
		bool flag=1;
		for (int b=sta[len]+1;b<=n;++b)
			if (!jc[b])
			{
				jc[sta[len]]=0;
				jc[b]=1;
				sta[len]=b;
				len++;
				flag=false;
				break;
			}
		if (flag){jc[sta[len]]=0;sta[len]=0;len--;}
	}
}
int main ()
{
	scanf ("%d",&n);
	dfs();
	return 0;
}
