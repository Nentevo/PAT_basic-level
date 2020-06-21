#include <iostream>

using namespace std;

int main()
{
	int num,i,flag=0,temp; //此处flag与temp均表示输入数字的位数，flag可变，temp固定
	int number[3]={0};
	cin>>num;
	for(i=2;(num/10)!=0 || (num%10)!=0;i--)
	{
		number[i]=num%10;
		num=num/10;
		flag++;
	}
	temp=flag;
  
	for(i=0;i<=2;i++)
	{
		if(flag==3)
		{
			while(number[i]>0)
			{
				cout<<"B";
				number[i]--;
			}
			flag--;
			continue;
		}
		if(flag==2)
		{
			if(temp==2) //如果数字只有两位17，则数组为{0,1,7}，需要手动移到第二位
				i=i+1;
			while(number[i]>0)
			{
				cout<<"S";
				number[i]--;
			}
			flag--;
			continue;
		}
		if(temp==1) //数字只有一位时同理
			i=i+2;
		while(flag<=number[i])
		{
			cout<<flag;
			flag++;
		}
	}
	return 0;
}
