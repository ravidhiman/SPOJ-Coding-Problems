// COSTLY CHESS


#include<iostream>
#include<limits.h>
using namespace std;
 
int a,b,c,d;
int dp[8][8];
int x[] = {1,-1, 1,-1,2, 2,-2,-2};
int y[] = {2, 2,-2,-2,1,-1, 1,-1};
 
bool isSafe(int i,int j,int dist)
{
	if(i>=0 && i<8 && j>=0 &&j<8 && dp[i][j] > dist)
		return true;
	return false;
}
 
void solve(int a1,int b1,int dist)
{
	dp[a1][b1] = dist;
 
	for(int i=0;i<8;i++)
	{
		if(isSafe(a1+x[i],b1+y[i],dist + a1*(a1+x[i]) + b1*(b1+y[i])))
		{
			solve(a1+x[i],b1+y[i],dist + a1*(a1+x[i]) + b1*(b1+y[i]));
		}
	}
}
 
int main()
{
	//freopen("input.txt","r",stdin);
	while(cin>>a)
	{
		cin>>b>>c>>d;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				dp[i][j] = INT_MAX;
			}
		}
		solve(a,b,0);
		cout<<dp[c][d]<<endl;
	}
	return 0;
} 
