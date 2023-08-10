#include<bits/stdc++.h>
using namespace std;
int n,q,p;
int d;
int ans,cnt=0x7f7f7f7f;
int main()
{
    cin>>n>>p>>q;
    for(int i=1;i<=n;i++)
    {
        int l=scanf("%d",&d);
        cnt=min(cnt,d);
    }
    ans=p;
    cnt+=q;
    cout<<min(ans,cnt);
	return 0;
}