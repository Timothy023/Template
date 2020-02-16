#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int len,ne[500005][26],T,n,root,fail[500005],ans,flag[500005];
char ss[100],s[1000005];
int main ()
{
    scanf ("%d",&T);
    while (T--)
    {
        scanf ("%d",&n);
        for (int b=0;b<=len;++b)flag[b]=fail[b]=0;
        len=1;ans=0;
        for (int b=0;b<26;++b)ne[root][b]=-1;
        for (int b=1;b<=n;++b)
        {
            scanf ("%s",ss);
            int m=strlen(ss),now=root;
            for (int c=0;c<m;++c)
            {
                if (ne[now][ss[c]-'a']==-1)
                {
                    for (int d=0;d<26;++d)ne[len][d]=-1;
                    ne[now][ss[c]-'a']=len;
                    len++;
                }
                now=ne[now][ss[c]-'a'];
            }
            flag[now]++;
        }
        
        int que[500000],tot=1,tow=0;
        for (int b=0;b<26;++b)
            if (ne[root][b]==-1)
                ne[root][b]=root;
            else
            {
                que[++tow]=ne[root][b];
                fail[ne[root][b]]=root;
            }
        while (tot<=tow)
        {
            int now=que[tot];
            for (int b=0;b<26;++b)
            {
                if (ne[now][b]==-1)
                    ne[now][b]=ne[fail[now]][b];
                else
                {
                    que[++tow]=ne[now][b];
                    fail[ne[now][b]]=ne[fail[now]][b];
                }
            }
            tot++;
        }
        
        scanf ("%s",s);
        int m=strlen(s),now=root;
        for (int b=0;b<m;++b)
        {
            now=ne[now][s[b]-'a'];
            int tmp=now;
            while (tmp!=root)
            {
                ans+=flag[tmp];
                flag[tmp]=0;
                tmp=fail[tmp];
            }
        }
        printf ("%d\n",ans);
    }
    return 0;
}
