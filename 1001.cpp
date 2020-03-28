#include<iostream>
#include<string>

using namespace std;

//int i;
////用于递归的全局变量声明

int Callatz(int num);

int main()
{
	int n;
	cin>>n;
        //i=0;
	cout<<Callatz(n)<<endl;
	return 0;
}

int Callatz(int num)
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

/*递归函数
int Callatz(int num)
{
	if(num==1)
		return i;
	i++;
	if(num%2==0)
		Callatz(num/2);
	else
		Callatz((3*num+1)/2);
	return i;
}
*/
