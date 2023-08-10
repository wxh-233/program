#include<bits/stdc++.h>
using namespace std;
int n,m;
int op,x,y,z;
vector<int>q;
int read()
{
    char ch=getchar();int f=1,ans=0;
    for(;ch<'0'||ch>'9';ch=getchar()) ch=='-'?f=-1:f=1;
    for(;ch>='0'&&ch<='9';ch=getchar()) ans=(ans<<3)+(ans<<1)+(ch&15);
    return f*ans;
}
int main()
{
	cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%d",&x),q.insert(lower_bound(q.begin(),q.end(),x),x);;
    while(m--)
    {
        op=read();x=read();
        x^=y;
        switch(op)
        {
            case 1:
                q.insert(lower_bound(q.begin(),q.end(),x),x);
            break;
            case 2:
                q.erase(lower_bound(q.begin(),q.end(),x));
            break;
            case 3:
                y=lower_bound(q.begin(),q.end(),x)-q.begin()+1;
                z^=y;
            break;
            case 4:
                y=q.at(x-1);
                z^=y;
            break;
            case 5:
                y=q.at(lower_bound(q.begin(),q.end(),x)-q.begin()-1);
                z^=y;
            break;
            case 6:
                y=q.at(upper_bound(q.begin(),q.end(),x)-q.begin());
                z^=y;
            break;
        }
    }
    cout<<z<<endl;
    /*
    q.begin() 开始指针的位置
    q.end() 结束指针的下一个位置
    q.at() 访问容器中第i个数的值 >> q[]
    q.insert() 把数插入第i个位置
    q.erase(q.begin()+i-1) 删除第i个数
    */
	return 0;
}