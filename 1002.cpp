#include<iostream>
#include<string.h>

using namespace std;

const char result[10][5]={"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};//不必后续再输出yi er等等，直接取此二维数组元素

int main()
{
	char str[105];
	char temp[10];
	cin>>str;
  
  //求和
	int i, sum=0;
	for (i=0;str[i]!='\0';i++)
		sum=sum+(str[i]-'0');
    
  //取各位数字放入temp[]，注意此时各位数字是从低位向高位取
	for (i=0;sum!=0;i++)
	{
		temp[i]=sum%10+'0'; //为方便理解，使temp[]中存放数字的ascii码
		sum=sum/10;
	}
	temp[i]='\0'; //为使用strlen()，得加结尾终止'\0'，因此必须定义temp[]为字符数组
  
  //输出
	int len,j=0;
	len=strlen(temp); //因为temp[]是倒序，因此必须求temp[]总长，再反向输出
	for(i=len-1;i>=0;i--)
	{
		j=((int)temp[i])-'0'; //temp中的元素代表ascii码，求数字相当于求其与ascii'0'的距离
		if(i!=0)
			cout<<result[j]<<" "; //由于result[][]是二维数组，因此result[3]将会输出san，result[3][1]将会输出a
		else
			cout<<result[j]<<endl;
	}
	return 0;
}
