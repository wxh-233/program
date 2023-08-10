#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	while(cin>>n)
		printf("%d\n",1+(n*(n-1)/2)+(n*(n-1)/2*(n-2)/3*(n-3)/4));
	return 0;
}