#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
using namespace std;
int n,len;
int a[1000005];
int op,l,r,c;
int sum[10005];
void add(int l,int r,int c)
{
    int x=(l-1)/len+1,y=(r-1)/len;
    if(x>=y)
    {
        for(int i=l;i<=r;i++) a[i]+=c;
        return;
    }
    for(int i=l;i<=x*len;i++) a[i]+=c;
    for(int i=y*len+1;i<=r;i++) a[i]+=c;
    for(int i=x+1;i<=y;i++) sum[i]+=c;
}
int main()
{
	cin>>n;
    len=sqrt(n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&op,&l,&r,&c);
        if(op==0) add(l,r,c);
        else printf("%d\n",a[r]+sum[(r-1)/len+1]);
    }
	return 0;
}
/*
k -> klen+1 ~ (k+1)len
i -> (i-1)/len+1
l -> (l-1)/len+1
r -> (r-1)/len
len=2
i:
1 -> 1
2 -> 1
3 -> 2
4 -> 2
5 -> 3
*/