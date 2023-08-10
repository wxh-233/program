#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define f(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
int n,m;
int op,x,y;
int a[1000005],t[1000005];
inline int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int y)
{
    for(int i=x;i<=n;i+=lowbit(i)) t[i]+=y;
}
int ask(int x)
{
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i)) ans+=t[i];
    return ans;
}
int main()
{
	cin>>n>>m;
    f(i,1,n) scanf("%d",&a[i]),add(i,a[i]);
    f(i,1,m)
    {
        scanf("%d%d%d",&op,&x,&y);
        if(op==1) add(x,y);
        else printf("%d\n",ask(y)-ask(x-1));
    }
	return 0;
}