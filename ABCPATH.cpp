#include<iostream>
#include<string.h>
#include<limits.h>
using namespace std;
 
int N,M;
char input[51][51];
long long int dp[51][51];
 
int x[] = {0, 0,1,1, 1,-1,-1,-1 };
int y[] = {1,-1,0,1,-1, 0, 1,-1};
bool visited[51][51];
 
bool isSafe(int x,int y,int prev_x,int prev_y)
{
	if(x>=0 && x<N && y>=0 && y<M && !visited[x][y] && (input[prev_x][prev_y]+1 == input[x][y]))
		return true;
	return false;
}
 
long long int findPath(int a,int b)
{
	if(dp[a][b] != -1)
		return dp[a][b];
 
	long long int ret = 1;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(isSafe(a+x[i],b+y[j],a,b))
				ret = max(ret,1 + findPath(a+x[i],b+y[j]));
		}
	}
	return dp[a][b] = ret;
}
 
int main()
{
//	freopen("input.txt","r",stdin);
	cin>>N>>M;
	int T=0;
	while(N!=0 && M!=0)
	{
		T++;
		memset(visited,false,sizeof(visited));
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<N;i++)
			cin>>input[i];
 
		long long int Ans = 0;
 
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				if(input[i][j] == 'A')
					Ans = max(Ans,findPath(i,j));
			}
		}
		cout<<"Case "<<T<<": ";
		cout<<Ans<<endl;
		cin>>N>>M;
	}
	return 0;
} 
