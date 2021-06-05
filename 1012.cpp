#include <iostream>
#include <cmath>  //使用取整函数floor()所需的头文件

using namespace std;

int main()
{
    int N,i,A2co=1,remainder,num[1000]={0};  //A2co表示正负交错的系数，每次计算后乘以-1即可实现
    float A[5]={0};  
    int flag[5]={0};  //flag表示对是否存在符合要求数字的判断，不存在则为0，存在则不为0

    cin >> N;
    for (i = 0; i < N;i++)
        cin >> num[i];
    for (i = 0; i < N;i++)
    {
        remainder = num[i] % 5;
        switch(remainder)  //switch语句表示判断
        {
            case 0:
                if(num[i]%2==0)  //switch语句的每个case中也可以加入if判断
                {
                    A[0] = A[0] + num[i];
                    flag[0] = 1;
                }
                break;  //当遇到break时，switch终止，控制流将跳转到switch语句后的下一行。如果case语句不包含break，控制流将会继续后续的case，直到遇到break为止。switch中的break只影响switch语句，不影响for循环
            case 1:
                A[1] = A[1] + A2co * num[i];
                A2co = A2co * (-1);
                flag[1] = 1;
                break;
            case 2:
                A[2]++;
                flag[2] = 1;
                break;
            case 3:
                A[3] = A[3] + num[i];
                flag[3]++;
                break;
            case 4:
                if(A[4] < num[i])
                    A[4] = num[i];
                flag[4] = 1;
                break;
        }

    }
    A[3] = floor((A[3]/flag[3]) * 10 + 0.5) / 10;  //先计算总和，再计算平均数

    /*C++中的四舍五入操作：
例如，需要对float a=3.14159保留两位小数，则可以利用floor()函数，需要头文件cmath或math.h
    a=floor(a * 100 + 0.5) / 100

floor()表示向下取整，即去尾法；ceil()表示向上取整，即进一法；round()表示四舍五入到整数；fix()表示向零方向取整
*/

    for (i = 0; i < 4;i++)
        flag[i] != 0 ? cout << A[i] << ' ' : cout << "N ";
    flag[4] != 0 ? cout << A[4] << endl : cout << "N"<< endl;
}
