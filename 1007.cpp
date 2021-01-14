#include <iostream>
#include <cmath>//sqrt需要math库函数

using namespace std;

//判断数字n是否为素数，可以通过遍历2到n-1，看n是否能被他们整除
//或者，令k=sqrt(n),只需判断n是否能被2到k整除即可。因为对任意合数n有a*b=n，若a<=k，则必有b>=k

int main()
{
	int n,i,j,k;
	int flag=0;//记录满足间距为2的素数对个数
	int pre=2;//指代前一个素数，从第一个素数2开始
	cin>>n;
  
	for(i=2;i<=n;i++)//不要从1开始，因为任何数都能被1整除
	{
		k=(int)sqrt((double)i);//sqrt()的参数为double类型，需要强制转换类型
		for(j=2;j<=k;j++)
		{	
			if(i%j == 0)
				break;
		}
		if(j>k)//当i是素数时，j++会一直执行，跳出小循环时j已经不满足j<=k
		{
			if(i-pre == 2)
			{
				flag++;
			}
			pre=i;
		}	
	}
  
	cout<<flag<<endl;
	return 0;
}
