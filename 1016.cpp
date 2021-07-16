#include <iostream>
#include <string>
#include <cmath>  //幂函数pow()所需的头文件

using namespace std;

//思路是将数字拆分到数组中，随后遍历数组看有无和DA、DB相同的数字并计数

int main()
{
    int A, DA, B, DB, PA=0, PB=0;  //PA和PB初始置零，若找不到数字的话，输出为0，因此不需要特别考虑没有相同数字的情况
    int i,count;
    float len;  //幂函数pow(底数, 指数)，其中底数和指数都是float或者double，如有需要可以强制转换为int
    int num[9] = {0};
    cin >> A >> DA >> B >> DB;
    string Astr = to_string(A);
    string Bstr = to_string(B);
    
    len = Astr.length();  //将数字转换为string类，随后可以方便地获取数字位数
    for (i = 0; i < len; i++)
    {
        num[i] = A / ((int)pow(10, len - i-1));  //通过整除(10^数字位数-1)可以获取当前位的数字
        A = A % ((int)pow(10, len - i - 1));  //通过对(10^数字位数-1)取余可以将A、B已经获取的数字位消除
    }
    count = 0;
    for (i = 0; i < len; i++)
    {
        if(DA==num[i])
            count++;
    }
    for (; count>0; count--)
    {
        PA = 10 * PA + 1;  //PA(或PB)的本质是111……1*DA(或DB)，111……1可以通过不断PA*10+1获得，循环次数和DA在数字A中的个数相同
    }

    len = Bstr.length();
    for (i = 0; i < len; i++)
    {
        num[i] = B / ((int)pow(10, len - i-1));
        B = B % ((int)pow(10, len - i - 1));
    }
    count = 0;
    for (i = 0; i < len; i++)
    {
        if(DB==num[i])
            count++;
    }
    for (; count>0; count--)
    {
        PB = 10 * PB + 1;
    }

    cout << PA * DA + PB * DB << endl;
}
