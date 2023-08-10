#include<bits/stdc++.h>
using namespace std;
int n;
int op,x;
vector<int>q;
int main()
{
	cin>>n;
    while(n--)
    {
        scanf("%d%d",&op,&x);
        switch(op)
        {
            case 1:
                q.insert(lower_bound(q.begin(),q.end(),x),x);
            break;
            case 2:
                q.erase(lower_bound(q.begin(),q.end(),x));
            break;
            case 3:
                printf("%d\n",lower_bound(q.begin(),q.end(),x)-q.begin()+1);
            break;
            case 4:
                printf("%d\n",q.at(x-1));
            break;
            case 5:
                printf("%d\n",q.at(lower_bound(q.begin(),q.end(),x)-q.begin()-1));
            break;
            case 6:
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