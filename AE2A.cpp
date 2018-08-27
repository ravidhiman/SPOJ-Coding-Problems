//Dice

#include<iostream>
#include<cmath>
using namespace std;
 
int N,K;
 
double dp[546][1909];
 
int main()
{
//	freopen("input.txt","r",stdin);
	int test_cases;
	cin>>test_cases;
	for(int T=1;T<=test_cases;T++)
	{
		cin>>N>>K;
		
		if(N>545 || K>1908)
		{
			cout<<"0"<<endl;
			continue;
		}
 
		for(int i=0;i<=N;i++)
		{
			for(int j=0;j<=K;j++)
			{
				if(i == 0 || j==0)
					dp[i][j] = 0;
				else if(i == 1)
				{
					if(j>=1 && j<=6)
						dp[i][j] = 1.0/6.0;
					else
						dp[i][j] = 0;
				}
				else
				{
					if(i>j)
						dp[i][j] = 0;
					else
					{
						dp[i][j] = dp[i-1][j-1];
						if(j-2 >=0 )
							dp[i][j] += dp[i-1][j-2];
						if(j-3 >=0 )
							dp[i][j] += dp[i-1][j-3];
						if(j-4 >=0 )
							dp[i][j] += dp[i-1][j-4];
						if(j-5 >=0 )
							dp[i][j] += dp[i-1][j-5];
						if(j-6 >=0 )
							dp[i][j] += dp[i-1][j-6];
						dp[i][j] = dp[i][j]/6.0;
					}
				}
			}
		}
		double ans = floor(dp[N][K]*100);
		cout<<ans<<endl;
	}
	return 0;
} 
