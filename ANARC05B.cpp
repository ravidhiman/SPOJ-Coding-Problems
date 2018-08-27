//The Double HeLiX

#include<iostream>
using namespace std;
 
int arr1[10000];
int arr2[10000];
int N,M;
 
long int findMaxSum()
{
	int idx1 = 0;
	int idx2 = 0;
	int prev_idx = -1;
	long int max_sum = 0;
	long int sum1 = 0,sum2 = 0;
	while(idx1 < N)
	{
		sum1 += arr1[idx1];
		sum2 = 0;
		for(int i = prev_idx+1;i<M;i++)
		{
			sum2 += arr2[i];
			if(arr1[idx1] == arr2[i])
			{
				prev_idx = i;
				if(sum1 > sum2)
					max_sum += sum1;
				else
					max_sum += sum2;
				sum1 = 0;
				break;
			}
			else if(arr1[idx1] < arr2[i])
			{
				break;
			}
		}
		idx1++;
	}
	sum2 = 0;
	for(int j=prev_idx+1;j<M;j++)
		sum2 += arr2[j];
	if(sum1 > sum2)
		max_sum += sum1;
	else
		max_sum += sum2;
 
	return max_sum;
}
 
int main()
{
	//freopen("input.txt","r",stdin);
	while(1)
	{
		cin>>N;
		if(N == 0)
			break;
		for(int i=0;i<N;i++)
			cin>>arr1[i];
		cin>>M;
		for(int i=0;i<M;i++)
			cin>>arr2[i];
		cout<<findMaxSum()<<endl;
	}
	return 0;
} 
