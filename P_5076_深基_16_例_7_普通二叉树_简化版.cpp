#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int op,x;
vector<int>q;
signed main()
{
	cin>>n;
    x=2147483647;x=-x;
    q.insert(lower_bound(q.begin(),q.end(),x),x);
    x=2147483647;
    q.insert(lower_bound(q.begin(),q.end(),x),x);
    while(n--)
    {
        scanf("%d%d",&op,&x);
        switch(op)
        {
            case 5:
                q.insert(lower_bound(q.begin(),q.end(),x),x);
            break;
            // case 6:
            //     q.erase(lower_bound(q.begin(),q.end(),x));
            break;
            case 1:
                printf("%d\n",lower_bound(q.begin(),q.end(),x)-q.begin());
            break;
            case 2:
                printf("%d\n",q.at(x+));
            break;
            case 3:
                printf("%d\n",q.at(lower_bound(q.begin(),q.end(),x)-q.begin()-1));
            break;
            case 4:
                printf("%d\n",q.at(upper_bound(q.begin(),q.end(),x)-q.begin()));
            break;
        }
    }
    /*
    q.begin() 开始指针的位置
    q.end() 结束指针的下一个位置
    q.at() 访问容器中第i个数的值 >> q[]
    q.insert() 把数插入第i个位置
    q.erase(q.begin()+i-1) 删除第i个数
    */
	return 0;
}