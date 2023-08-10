#include<bits/stdc++.h>
#define int unsigned long long
#define guo continue
#define tiao break
#define g return 0
using namespace std;
typedef int haxi;
haxi ha[400005],mod[400005];
int t;
char s[400005];
signed main()
{
	mod[1]=1;
	mod[2]=31;
	for(int i=3;i<=400005;i++)
		mod[i]=mod[i-1]*mod[2];
	while(cin>>s+1)
	{
		int len=strlen(s+1);
		for(int i=1;i<=len;i++)
			ha[i]=ha[i-1]*31+(s[i]-'A'+1);
		for(int i=1;i<=len;i++)
			if(ha[i]==ha[len]-ha[len-i]*mod[i+1])
				cout<<i<<" ";cout<<endl;
	}
	g;
}
/*
aaaaa
1 4
 
ha[5]-ha[4]*mod[
*/
//给定若干长度小于等于400 000的字符串，在每个字符串中求出所有既是前缀又是后缀的子串长度。如ababcababababcabab，既是前缀又是后缀的有：ab,abab,ababcabab,ababcababababcabab。