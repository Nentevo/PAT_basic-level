#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    int flag=0, countnum=1, i,j,k;  //flag表示素数个数，countnum表示输出的素数个数，分开以便于每十个换行
    
    for (i = 2;flag<=N;i++)
    {
        k=(int)sqrt((double)i);  //素数判断思路可参考题目1007，只需要判断2~sqrt(i)有无i的因数即可，不需要遍历2到i-1
        for (j = 2;j<=k;j++)
        {
            if(i%j == 0)
                break;
        }
        if(j>k)  //当j>k时，说明2~sqrt(k)均不是i的因数，即i为素数
        {
            flag++;
            if(flag>=M && flag<N)
            {
                if(countnum == 10)
                {
                    cout << i << endl;
                    countnum = 1;
                }
                else
                {
                    cout << i << ' ';
                    countnum++;
                }
            }
            if(flag == N)  //题目要求最后一个输出(即第N个素数)后无空格
                cout << i << endl;
        }
    }
}
