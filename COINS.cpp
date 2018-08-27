//Bytelandian gold coins

#include<stdio.h>
#include<iostream>
typedef long long int lli;
using namespace std;
 
 
 
lli BT(int a,int arr[])
{
	if(a/2 + a/3 + a/4 > a)
	{
		lli temp = 0;
		if(a/2 <= 100000 && arr[a/2])
			temp += arr[a/2];
		else
			temp += BT(a/2,arr);
		if(a/3 <= 100000 && arr[a/3])
			temp += arr[a/3];
		else
			temp += BT(a/3,arr);
		if(a/4 <= 100000 && arr[a/4])
			temp += arr[a/4];
		else
			temp += BT(a/4,arr);
		return temp;
	}
	else
	{
		if(a <= 100000)
			arr[a] = a;
		return a;
	}
}
 
int main() {
	
	// your code here
	
int a;
	//freopen("input.txt","r",stdin);
	while(cin>>a)
	{
		int arr[100001] = {0};
		/*for(int i=0;i<1000000;i++)
			arr[i] = 0;*/
		cout<<BT(a,arr)<<endl;
	}
	return 0;
}
