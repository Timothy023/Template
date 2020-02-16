#include<iostream>
#include<string>
#include<cstdio>
#define maxn 110010
using namespace std;
char s[maxn],ss[maxn<<1];
int m,p[maxn<<1],ans,maxid,id,b;
int Min(int i,int j){return i<j?i:j;}
int main ()
{
    while (scanf ("%s",&ss[1])!=EOF)
    {
        maxid=ans=m=0;
        s[0]='$';s[++m]='#';
        for (b=1;ss[b]!='\0';++b)
        {
            s[++m]=ss[b];
            s[++m]='#';
        }
        s[++m]='?';
        for (int i=1;i<m;++i)
        {
            if (maxid>i)p[i]=Min(maxid-i,p[2*id-i]);
            else p[i]=1;
            while (s[i-p[i]]==s[i+p[i]])p[i]++;
            if (i+p[i]>maxid){maxid=i+p[i];id=i;}
            if (p[i]>ans)ans=p[i];
        }
        printf ("%d\n",ans-1);
    }
    return 0;
}
