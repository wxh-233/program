#include<bits/stdc++.h>
#define int unsigned long long
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define f(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
int read()
{
    char ch=getchar();int f=1,ans=0;
    for(;ch<'0'||ch>'9';ch=getchar()) ch=='-'?f=-1:f=1;
    for(;ch>='0'&&ch<='9';ch=getchar()) ans=(ans<<3)+(ans<<1)+(ch&15);
    return f*ans;
}
int t,n;
string s;
int x;
signed main()
{
	cin>>t;
    while(t--)
    {
        n=read();
        stack<int>q;
        while(n--)
        {
            cin>>s;
            if(s=="push")
                x=read(),q.push(x);
            if(s=="query")
            {
                if(q.empty()) printf("Anguei!\n");
                else printf("%llu\n",q.top());
            }
            if(s=="pop")
            {
                if(q.empty()) printf("Empty\n");
                else q.pop();
            }
            if(s=="size") printf("%llu\n",q.size());
        }
    }
	return 0;
}