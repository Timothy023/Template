#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<set>
using namespace std;
set < string > st;
string s;
int sum,n;
int main ()
{
	cin >>n;
	for (int b=1;b<=n;++b)
	{
		cin >>s;
		if (st.find(s)==st.end())
		{
			sum++;
			st.insert(s);
		}
	}
	cout <<sum;
	return 0;
}
