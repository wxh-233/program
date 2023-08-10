#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
using namespace std;
int n,k;
int main()
{
	cin>>n>>k;n*=2;
    cout<<k+1;
	for(int i=1;i<=n;i++)
		if(i!=k+1)
            printf(" %d",i);
    return 0;
}
