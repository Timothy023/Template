#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
int flag[300001];
int len=0,root=0,n,next[300001][30];
char s[10005][30];
int main ()
{
    while (scanf ("%s",s[++n])!=EOF)
    {
        int now=root;
        for (int b=0;b<strlen(s[n]);++b)
        {
            ++flag[now];
            if (next[now][s[n][b]-'a']==0)
                next[now][s[n][b]-'a']=(++len);
            now=next[now][s[n][b]-'a'];
        }
        ++flag[now];
    }
    for (int b=1;b<=n;++b)
    {
        string ans="";
        int now=root;
        for (int c=0;c<strlen(s[b]);++c)
        {
            if (flag[now]==1)break;
            now=next[now][s[b][c]-'a'];
            ans+=s[b][c];
        }
        printf ("%s ",s[b]);cout <<ans<<endl;
    }
    return 0;
}




