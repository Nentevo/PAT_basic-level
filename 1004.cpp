#include<iostream>
#include<string>//使用string类必须要声明的头文件

using namespace std;

/*一开始列了一大堆变量，后来用类&结构体就解决了，简单明了

  注意当cin和getline()混用时：由于cin的流提取运算符会根据它后面的变量类型读取数据，从非空白符号开始，遇到Enter、Space、Tab键时结束。
  getline()函数从istream中读取一行数据，当遇到"\n"时结束返回。 
  造成程序错误结果的原因是，用户输入结束后按回车结束输入，把"\n"留在了输入流里；
  而cin不会主动删除输入流内的换行符，这样换行符就被getline()读取到，getline()遇到换行符返回，因此程序不会等待用户输入。 
  
  解决办法:  
      cin>>n;
      cin.ignore();或者cin.ignore(1024,'\n');
      getline(cin, str);*/

class list
{
	public:
	string name;
	string number;
	int score;
};

/*
struct list
{
	string name;
	string number;
	int score;
};
*/

//C++结构体和类的主要区别在于结构体和类具有不同的默认访问控制属性
//类中对于未指定访问控制属性的成员，其访问控制属性为private，因此需声明是public
//结构体中对于未指定访问控制属性的成员，其访问控制属性为public

int main()
{
	int n,i;
	cin>>n;
	list stu,bstu,wstu;//分别代表输入的学生信息，当前最高分的学生信息，当前最低分的学生信息
	for(i=1;i<=n;i++)
	{
		cin>>stu.name>>stu.number>>stu.score;//cin在遇到空格时自动停止，如果想输入带空格的字符串可以使用getline()函数
    
		if(i==1)//让第一次循环中的最好和最差的成绩都被赋值
		{
			bstu.score=stu.score;
			wstu.score=stu.score;
		}
    
		if(stu.score>=bstu.score)
		{
			bstu.name.assign(stu.name);
			bstu.number.assign(stu.number);
			bstu.score=stu.score;
		}
		if(stu.score<=wstu.score)
		{
			wstu.name.assign(stu.name);
			wstu.number.assign(stu.number);
			wstu.score=stu.score;
		}
	}
	cout<<bstu.name<<" "<<bstu.number<<endl;
	cout<<wstu.name<<" "<<wstu.number<<endl;
	return 0;
}
