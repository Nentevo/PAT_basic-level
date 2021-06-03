#include <iostream>

using namespace std;

/*在1004.cpp中也有类似，cin的流提取运算符会根据它后面的变量类型读取数据，从非空白符号开始，遇到enter、space、tab键时结束
cin.get()在无参时只读取一个字符，可以是回车
以此来建立二维字符串数组，数组每一行都可以接收一个单词，每次遇到space都表示一行的结束
而最后一行用enter结束后，转义字符"\n"留在了输入流里，随后利用cin.get()读取\n
这样便完成了二维数组的建立，同时也将句子分成了若干单词，最后倒序输出*/

int main()
{
    char str[40][80];  //考虑极端情况，仅有一个长为80的单词、以及40个仅有一个字母组成的单词
    int i,j;
    char ch;

    for (i = 0;;i++)  //建立死循环，直到读入enter便break跳出
    {
        cin >> str[i];  //二维数组str[x]是一个指针，指向元素str[x][0]
        ch = cin.get();
        if(ch == '\n')
            break;
    }

    for (j = i; j > 0;j--)
        cout << str[j] << ' ';
    cout << str[0] << endl; //第一个词输出后不加空格
}
