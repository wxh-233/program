#include<bits/stdc++.h>
using namespace std;
struct Standings{
	long double a,b;
	int id;
}t[200005];
bool cmp(Standings x,Standings y)
{
	if((x.a/(x.a+x.b))==(y.a/(y.a+y.b)))
		return x.id<y.id;
	else
		return (x.a/(x.a+x.b))>(y.a/(y.a+y.b));
}
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>t[i].a>>t[i].b,t[i].id=i;
	sort(1+t,1+t+n,cmp);
	for(int i=1;i<=n;i++)
		cout<<t[i].id<<" ";
	return 0;
}
/*
1   0.25
2   0.75
3   0.50

2 3 1
*/