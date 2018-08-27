//Alphacode
#include <iostream>
using namespace std;

char input[5000];
int output[5000];

int len()
{
	int i=0;
	while(input[i] != '\0')
	{
		i++;
	}
	return i;
}

int cal(int len)
{
	output[0] = 1;
	//cout<<input[0]<<endl;
	for(int i=1;i<len;i++)
	{
		if(input[i] == 48)
			output[i] = 0;
		else
			output[i] = output[i-1];
		int temp = input[i-1]-48;
		if(temp != 0)
		{
			temp = temp*10 + (input[i]-48);
			if(temp >0 && temp <=26 )
			{
				if(i-2 >= 0)
					output[i] += output[i-2];
				else
					output[i] += 1;
			}
		}
	}
	return output[len-1];
}

int main() 
{
	//freopen("input.txt","r",stdin);
	while(1)
	{
		cin>>input;
		if(input[0] == '0')
			break;
		cout<<cal(len())<<endl;
	}
	return 0;
}
