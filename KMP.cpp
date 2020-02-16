#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
string s1,s2;
int p[202],j;
int main ()
{
    cin >>s1>>s2;
    int n=s1.size(),m=s2.size();
    s1=" "+s1;s2=" "+s2;
    j=0;
    for (int i=2;i<=m+1;++i)
    {
        while (j>0 && s2[j+1]!=s2[i])j=p[j];
        if (s2[j+1]==s2[i])j++;
        p[i]=j;
    }
    j=0;
    for (int i=1;i<=n+1;++i)
    {
        while (j>0 && s2[j+1]!=s1[i])j=p[j];
        if (s2[j+1]==s1[i])j++;
        if (j==m){printf ("%d",i-j+1);break;}
    }
    return 0;
}
