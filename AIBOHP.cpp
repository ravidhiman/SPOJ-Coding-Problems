//Aibohphobia

#include<iostream>
using namespace std;
 
char str[6101];
int dp[6101][6101];
 
int str_length()
{
	int i=0;
	while(str[i] != '\0')
		i++;
	return i;
}
 
int LCS(int len)
{
	for(int i=0;i<=len;i++)
	{
		for(int j=0;j<=len;j++)
		{
			if(i==0 || j==0)
				dp[i][j] = 0;
			else
			{
				if(str[i-1] == str[len-j])
					dp[i][j] = 1 + dp[i-1][j-1];
				else
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[len][len];
}
 
int main()
{
	//freopen("input.txt","r",stdin);
	int cases;
	cin>>cases;
	for(int T=1;T<=cases;T++)
	{
		cin>>str;
		int len = str_length();
		cout<<len-LCS(len)<<endl;
	}
	return 0;
} 
