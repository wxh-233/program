#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define f(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
int t,n;
int ans,x;
int main()
{
	cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        ans=0;
        f(i,1,n) scanf("%d",&x),ans^=x;
        if(!ans) printf("No\n");
        else printf("Yes\n");
    }
	return 0;
}