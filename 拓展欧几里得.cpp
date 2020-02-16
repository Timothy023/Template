#include<iostream>
using namespace std;
void gcd(int a,int b,int *x,int *y)
{
     if (b==0){(*x)=1;(*y)=0;}
     else {gcd (b,a%b,y,x);(*y)-=(*x)*(a/b);}
}
int main ()
{
    long long a,b;
    int x,y;
    scanf ("%d %d",&a,&b);
    gcd (a,b,&x,&y);
    while (x<0)x+=b;
    printf ("%d",x);
    return 0;
}
