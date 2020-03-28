#include<iostream>
#include<cstring>

using namespace std;

/*题目一开始没读懂，经检验得知要求有：
1. 必须有且仅有1个P和一个T，不能有PAT之外的字母；
2. P与T之间A的数量不限，但不能为0(因为PAT正确，所以PAAT也正确，由此PAAAT也正确，以此类推，但无法反推PT正确)；
3. 形如aPbTc，需要满足a*b=c.*/

int main()
{
	int n,i,j,flag,ppos,tpos,pnum=0,tnum=0,aleft,aright,amiddle;//ppos与tpos确定P和T的位置，pnum要求P和T分别有且仅有一个，后三个用来记录A的数目
	cin>>n;
	char ch[10][100];
	for(i=0;i<=n-1;i++)//最大十行，ch[0][]~ch[9][]
		cin>>ch[i];
	for(i=0;i<=n-1;i++)
	{
		pnum=0;
		tnum=0;
		flag=1;//flag用来记录除了PAT三字母之外的字母出现的情况，如果有直接NO；每次小循环之后要重置回1
		for(j=0;ch[i][j]!='\0';j++)
		{
			if((ch[i][j]!='P')&&(ch[i][j]!='A')&&(ch[i][j]!='T'))
			{
				flag=0;
				break;
			}
			if(ch[i][j]=='P')
			{
				ppos=j;
				pnum++;
			}
			if(ch[i][j]=='T')
			{
				tpos=j;
				tnum++;
			}
		}
		if((flag==1)&&(pnum==1)&&(tnum==1))
		{
			aleft=ppos;
			amiddle=tpos-ppos-1;
			aright=strlen(ch[i])-tpos-1;
			if((aright==aleft*amiddle)&&(amiddle!=0))//满足a*b=c，且有b!=0(反例PT)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
