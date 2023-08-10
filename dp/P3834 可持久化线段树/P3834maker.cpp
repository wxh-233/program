#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
signed main()
{
    srand(time(0));
    int n=10000,/*rand()%5000+5000,*/m=1;//rand()%5+5;
    cout<<n<<" "<<m<<endl;
    for(int i=1;i<=n;i++)
        a[i]=rand()%((int)(9e8))+1e8,printf("%lld ",a[i]);
    cout<<endl;
    for(int i=1;i<=m;i++)
    {
        int x,y,z=1;
        x=rand()%n+1;
        y=rand()%(n-x+1)+x;
        z=rand()%(y-x+1)+1;
        printf("%lld %lld %lld\n",x,y,z);
    }
    return 0;
}