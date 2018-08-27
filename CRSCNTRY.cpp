//Cross-country

#include<iostream>
using namespace std;
 
int arr1[2000];
int arr2[2000];
int dp[2001][2001];
int len1,len2;
 
int main()
{
//	freopen("input.txt","r",stdin);
	int test_cases;
	cin>>test_cases;
	int x;
	for(int T=1;T<=test_cases;T++)
	{
		int ans = -1;
		int i = 0;
		cin>>x;
		while(x != 0)
		{
			arr1[i++] = x;
			cin>>x;
		}
		len1 = i;
		i = 0;
		cin>>x;
		while(1)
		{
			while(x != 0)
			{
				arr2[i++] = x;
				cin>>x;
			}
			len2 = i;
 
			for(int j=0;j<=len1;j++)
			{
				for(int k=0;k<=len2;k++)
				{
					if(j == 0 || k == 0)
						dp[i][j] = 0;
					else if(arr1[j-1] == arr2[k-1])
						dp[j][k] = dp[j-1][k-1] + 1;
					else
						dp[j][k] = max(dp[j-1][k],dp[j][k-1]);
				}
			}
			ans = max(ans,dp[len1][len2]);
 
			i = 0;
			cin>>x;
			if(x == 0)
				break;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
