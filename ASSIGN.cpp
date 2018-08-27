//Assignments

#include<iostream>
#include<string.h>
using namespace std;
 
int N;
int map[21][21];
long long int dp[1048576][21];
int allmasks;
 
long long int countWays(int mask,int i)
{
	if(allmasks == mask)
		return 1;
	if(i>=N)
		return 0;
	
	if(dp[mask][i] != -1)
		return dp[mask][i];
 
	long long int ways = 0;
	for(int j=0;j<N;j++)
	{
		if(1<<j & mask)
			continue;
		if(map[i][j])
			ways += countWays(mask | (1<<j),i+1);
	}
	return dp[mask][i] = ways;
}
 
int main()
{
//	freopen("input.txt","r",stdin);
	int test_cases;
	cin>>test_cases;
	for(int T=1;T<=test_cases;T++)
	{
		cin>>N;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cin>>map[i][j];
			}
		}
		memset(dp,-1,sizeof(dp));
		allmasks = (1<<N) - 1;
		cout<<countWays(0,0)<<endl;
	}
	return 0;
} 
