//Magic Grid

#include<iostream>
using namespace std;
 
int R,C;
int map[501][501];
int dp[501][501];
 
int main()
{
//	freopen("input.txt","r",stdin);
	int test_cases;
	cin>>test_cases;
	for(int T=1;T<=test_cases;T++)
	{
		cin>>R>>C;
		for(int i=1;i<=R;i++)
		{
			for(int j=1;j<=C;j++)
				cin>>map[i][j];
		}
	
		dp[R][C] = 1;
		for(int i=R-1;i>=1;i--)
		{
			if(map[i][C] >= dp[i+1][C])
				dp[i][C] = 1;
			else
				dp[i][C] = dp[i+1][C] - map[i][C];
		}
		for(int i=C-1;i>=1;i--)
		{
			if(map[R][i] >= dp[R][i+1])
				dp[R][i] = 1;
			else
				dp[R][i] = dp[R][i+1] - map[R][i];
		}
		for(int i=R-1;i>=1;i--)
		{
			for(int j=C-1;j>=1;j--)
			{
				int val = min(dp[i+1][j],dp[i][j+1]);
				if(val > map[i][j])
					dp[i][j] = val - map[i][j];
				else
					dp[i][j]  = 1;
			}
		}
		cout<<dp[1][1]<<endl;
	}
	return 0;
} 
