// Philosophers Stone

#include<iostream>
using namespace std;
 
int arr[101][101];
int h,w;
 
int dp()
{
	for(int i=h-1;i>=1;i--)
	{
		for(int j=1;j<=w;j++)
		{
			int temp = j-1;
			int val = arr[i][j];
			if(temp>0)
			{
				if(arr[i+1][temp] + arr[i][j] > val)
					val = arr[i+1][temp] + arr[i][j];
			}
			
			if(arr[i+1][j] + arr[i][j] > val)
				val = arr[i+1][j] + arr[i][j];
			
			temp = j+1;
			if(temp<=w)
			{
				if(arr[i+1][temp] + arr[i][j] > val)
					val = arr[i+1][temp] + arr[i][j];
			}
			arr[i][j] = val;
		}
	}
	int max_val = arr[1][1];
	for(int i=2;i<=w;i++)
	{
		if(max_val < arr[1][i])
			max_val = arr[1][i];
	}
	return max_val;
}
 
int main()
{
	//freopen("input.txt","r",stdin);
	int N;
	cin>>N;
	for(int T=1;T<=N;T++)
	{
		cin>>h>>w;
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				cin>>arr[i][j];
			}
		}
		cout<<dp()<<endl;
	}
 
	return 0;
} 
