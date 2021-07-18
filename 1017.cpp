#include <iostream>

using namespace std;

/*对于题目要求的1000位的长正整数，int甚至long都不能达到要求，所以只能将每位数字保存，利用除法列竖式计算的原理逐个输出商的位数、最后输出余数
因此想到利用字符/字符串来迂回操作
建立字符数组，利用字符数组每一元素仅为一个字符的特性，将长正整数每位分离，随后与0的ASCII码值相减，就能得到每一位的数值
*/

int main()
{
    char inputnum[1001];  //字符数组以\0为结尾，为便于终止判断，上限为1001
    int A[1000]={-1};
    int len=0, i, B, R=0;
    cin >> inputnum >> B;  //对于字符数组可以直接cin>>(字符数组名)，输出时也可以cout<<(字符数组名)；对于普通数字数组不能这么做，需要利用循环
    while (inputnum[len] != '\0')
    {
        A[len] = inputnum[len] - '0';
        len++;
    }

//首项单独考虑
    R = A[0] % B;
    if(A[0]>=B)
    {
        cout << A[0] / B;
    }
    else
    {
        if(len==1)
            cout << "0"; //被除数只有1位、第一项又无法整除除数的情况下，商为0，余数等于被除数;若被除数位数>=2，则商的第一位不写0
    }

    for (i = 1; i < len; i++)
    {
        cout << (10 * R + A[i]) / B;  //前一位的余数到这一次运算时需要乘10
        R = (10 * R + A[i]) % B;
    }
    cout << ' ' << R << endl;
}