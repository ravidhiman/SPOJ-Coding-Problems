// Buying Apples!

#include<iostream>
using namespace std;
#define INT_MAX 2147483647
 
int cases,N,K,k,n,l;
int dp[100][101];
int price[101];
int weight[101];
 
int MinMoney()
{
	for(int i=0;i<=l;i++)
	{
		n = 0;
		for(int j=0;j<=K;j++)
		{
			if(j == 0)
				dp[i][j] = 0;
			else if(i == 0)
				dp[i][j] =	INT_MAX;
			else
			{
				if(weight[i]>j)
					dp[i][j] = dp[i-1][j];
				else
				{
					if(dp[i][j-weight[i]] != INT_MAX)
					{
						//n++;
						//if(n<=N)
						//{
							dp[i][j] = min(dp[i-1][j],price[i] + dp[i][j-weight[i]]);;
						//}
						//else
						//	dp[i][j] = INT_MAX;
					}
					else
						dp[i][j] = INT_MAX;
				}	
			}
		}
	}
	return dp[l][K];
}
 
int main()
{
	//freopen("input.txt","r",stdin);
	cin>>cases;
	for(int i=0;i<cases;i++)
	{
		cin>>N>>K;
		int x;
		l = 0;
		for(int j=1;j<=K;j++)
		{
			cin>>x;
			if(x != -1)
			{
				price[++l] = x;
				weight[l] = j;
			}
		}
		int out = MinMoney();
		if(out != INT_MAX)
			cout<<out<<endl;
		else
			cout<<"-1"<<endl;
	}
 
	return 0;
} 
