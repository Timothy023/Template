#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
string s1,s2;
int i[10001],j[10001],ans[10001],leni,lenj,lenans,u;
int main ()
{
    cin >>s1 >>s2;
    leni=s1.size();u=leni;if (u%4) for (int b=4;b>u%4;--b){leni++;s1='0'+s1;}
    lenj=s2.size();u=lenj;if (u%4) for (int b=4;b>u%4;--b){lenj++;s2='0'+s2;}
    u=leni;leni=0;
    for(int b=0;b<u;b+=4)
        i[u/4-(++leni)+1]=s1[b+3]-'0'+(s1[b+2]-'0')*10+(s1[b+1]-'0')*100+(s1[b]-'0')*1000;
    u=lenj;lenj=0;
    for(int b=0;b<u;b+=4)
        j[u/4-(++lenj)+1]=s2[b+3]-'0'+(s2[b+2]-'0')*10+(s2[b+1]-'0')*100+(s2[b]-'0')*1000;
    for (int b=1;b<=leni;++b)
    {
        int sum=0;
        for (int c=1;c<=lenj;++c)
        {
            ans[b+c-1]+=i[b]*j[c]+sum;
            sum=ans[b+c-1]/10000;
            ans[b+c-1]%=10000;
        }
        ans[b+lenj]=sum;
    }
    lenans=leni*4+lenj*4;
    while (ans[lenans]==0 && lenans>1)lenans--;
    printf ("%d",ans[lenans]);
    for (int b=lenans-1;b>=1;--b)
    {
        if (ans[b]<1000)
        {
            printf ("0");
            if (ans[b]<100)
            {
                printf ("0");
                if (ans[b]<10)printf ("0");
            }
        }
        printf ("%d",ans[b]);
    }
    return 0;
}
