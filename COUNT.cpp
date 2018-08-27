// Another Very Easy Problem! WOW!!!

#include<iostream>
using namespace std;
 
int N,K;
int dp[5001];
int save;
 
int cal_ways()
{
	for(int j=1;j<=N;j++)
	{
		dp[j] = 0;
	}
	dp[0] = 1;
	for(int i=1;i<=K;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(j>=i)
				dp[j] = (dp[j]%1988) + (dp[j-i]%1988);
			if(i==K-1 && j==N)
				save = dp[j]%1988;
		}
	}
	return dp[N] - save;
}
 
int main()
{
	//freopen("input.txt","r",stdin);
	cin>>N>>K;
	while(N!=0 && K!=0)
	{
		cout<<cal_ways()<<endl;
		cin>>N>>K;
	}
	return 0;
} 
