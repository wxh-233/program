#include<bits/stdc++.h>
using namespace std;
int n;
int a[1005];
int main()
{
	cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<a[1]<<" ";
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1])
            for(int j=a[i-1]+1;j<a[i];j++) cout<<j<<" ";
        else
            for(int j=a[i-1]-1;j>a[i];j--) cout<<j<<" ";
        cout<<a[i]<<" ";
    }
	return 0;
}