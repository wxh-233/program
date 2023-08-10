#include<bits/stdc++.h>
using namespace std;
int a[10];
bool flag=0;
int main()
{
	for(int i=1;i<=8;i++)
		cin>>a[i];
	if(100>a[1]||675<a[1]) flag=1;
	if(a[1]%25) flag=1;
	for(int i=2;i<=8;i++)
	{
		if(100>a[i]||675<a[i]) flag=1;
		if(a[i]%25) flag=1;
		if(a[i]<a[i-1]) flag=1;
	}
	if(!flag) cout<<"Yes";
	else cout<<"No";
	return 0;
}