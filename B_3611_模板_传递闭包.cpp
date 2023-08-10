#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define f(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
int n;
int dt[105][105];
int main()
{
	cin>>n;
    f(i,1,n) f(j,1,n) scanf("%d",&dt[i][j]);
    f(k,1,n) f(i,1,n) f(j,1,n) if(dt[i][k]&&dt[k][j]) dt[i][j]=1;
    f(i,1,n) {f(j,1,n) printf("%d ",dt[i][j]);putchar('\n');}
	return 0;
}