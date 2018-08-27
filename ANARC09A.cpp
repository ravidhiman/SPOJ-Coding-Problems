//Seinfeld

#include<iostream>
#include<stdio.h>
using namespace std;
 
char str[2001];
 
int length()
{
	int i =0;
	while(str[i] != '\0')
		i++;
	return i;
}
 
int findMinOperations()
{
	int i = 0;
	int count = 0;
	int top = 0;
	int len = length();
	while(str[i] != '\0')
	{
		if(top == 0 )
		{
			if(str[i] == '}')
			{
				count++;
			}
			++top;
		}
		else
		{
			if(top >= len-i )
			{				
				if(str[i] == '{')
				{
					count++;
				}
				top--;
			}
			else if(str[i] == '{')
			{
				++top;
			}
			else
			{
				top--;
			}	
		}
		++i;
	}
	return count;
}
 
int main()
{
	//freopen("input.txt","r",stdin);
	int count = 1;
	while(1)
	{
		scanf("%s",str);
		if(str[0] == '-')
			break;
		cout<<count<<". "<<findMinOperations()<<endl;
		count++;
	}
	return 0;
} 
