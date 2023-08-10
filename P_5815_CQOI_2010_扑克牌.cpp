#include<bits/stdc++.h>
#define guo continue
#define tiao break
#define g return 0
using namespace std;
int n,m,a[55];
int zj(int x)
{
    long long k=0;
    for(int i=1;i<=n;i++)
        k+=max(0,x-a[i]);
    if(k<=min(m,x)) return 1;
    return 0;
}
int main()
{
	cin>>n>>m;
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    int l=0,r=1e9,mid=l+r>>1;
    while(l+1<r) 
    {
		mid=(l+r)>>1;
		if(zj(mid)) l=mid;
		else r=mid;
    }
    printf("%d",l);
    g;
}