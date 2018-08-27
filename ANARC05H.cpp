// Chop Ahoy! Revisited!

#include<iostream>
using namespace std;
 
char str[26];
 
int length()
{
	int i = 0;
	while(str[i] != '\0')
		i++;
	return i;
}
 
void TotalGrouping(int idx,int len,int & total,int prev_val)
{
	if(idx >= len)
	{
		total++;
		return;
	}
	int cur_val = 0;
	for(int i = idx;i<len;i++)
	{
		cur_val += (str[i]-48);
		if(cur_val >= prev_val)
			TotalGrouping(i+1,len,total,cur_val);
	}
}
 
int main()
{
	//freopen("input.txt","r",stdin);
	int count = 1;
	while(1)
	{
		cin>>str;
		if(str[0] == 'b')
			break;
		int len = length();
		int total = 0;
		int prev_val = 0;
		for(int i=0;i<len;i++)
		{
			prev_val += (str[i]-48);
			TotalGrouping(i+1,len,total,prev_val);
		}
		cout<<count<<". "<<total<<endl;
		++count;
	}
	return 0;
} 
