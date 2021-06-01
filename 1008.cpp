#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
    int M, N, modnum,i;
    int num[100] = {0};
    
    cin >> N >> M;  //cin>> 以空格、回车、tab为分隔读取
    
    for (i = 0; i < N;i++)
        cin >> num[i];  //理由同上，cin>> 以空格、回车、tab为分隔读取，对于以空格分隔的数字序列可以用这种方式输入到一维数组中
        
    modnum = M % N; //简化循环位数大于序列长度的情况，确定循环右移起始点
    
    for (i = (N - modnum); i < N;i++)
        cout << num[i] << " ";  //先输出循环起始点右侧的数字
    for (i = 0; i < (N - modnum-1);i++)
        cout << num[i] << " ";  //再输出循环起始点左侧的数字
    cout << num[i] << endl;  //因为结尾不能有空格，所以循环起始点左侧第一位的需要单独输出
    //此时 i=(N-modnum)
}
