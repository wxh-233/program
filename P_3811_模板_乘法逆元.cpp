#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,p;
int a[3000005];
signed main()
{
	cin>>n>>p;
    a[1]=1;cout<<1<<endl;
    for(int i=2;i<=n;i++)
        printf("%lld\n",a[i]=((p-p/i)*a[p%i]%p));
	return 0;
}