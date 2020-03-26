#include<iostream>
#include<string.h>

using namespace std;
//int i;
////用于递归的全局变量声明
int splice(int num);

int main()
{
	int n;
	cin>>n;
        //i=0;
	cout<<splice(n)<<endl;
	return 0;
}

int splice(int num)
{
	int i=0;
	for(;num!=1;i++)
	{
		if(num%2==0)
			num=num/2;
		else
			num=(3*num+1)/2;
	}
	return i;
}

/*
int splice(int num)
{
	if(num==1)
		return i;
	i++;
	if(num%2==0)
		splice(num/2);
	else
		splice((3*num+1)/2);
	return i;
}
*/
