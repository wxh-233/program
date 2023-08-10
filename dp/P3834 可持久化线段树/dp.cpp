#include<bits/stdc++.h>
using namespace std;
int main()
{
    system("g++ -std=c++14 P3834.cpp -o my");
    system("g++ -std=c++14 P3834tj.cpp -o tj");
    system("g++ -std=c++14 P3834maker.cpp -o make");
    for(int i=1;i<=1000;i++)
    {
        cout<<i<<endl;
        system("./maker >> maker.in");
        system("./tj << maker.in >> tj.out");
        system("./my << maker.in >> my.out");
        system("diff tj.out my.out");
    }
    return 0;
}