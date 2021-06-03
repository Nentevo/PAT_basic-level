#include <iostream>

using namespace std;
//在线读入数据，边读入边处理，之后输入需要用while(cin>>A>>B)

int main()
{
    int coefficientNum, indexNum;

    cin >> coefficientNum >> indexNum;
    if(indexNum == 0)  //因为要输出零多项式，只可能发生在形如x 0的情况下，也即单项式
        cout << "0 0";
    else
        cout << coefficientNum * indexNum << ' ' << indexNum - 1;
    //进行第一对系数和指数的计算，之后的计算只需要在计算前加空格即可满足输出末尾不要空格的要求

    while(cin >> coefficientNum >> indexNum)  //相当于C中的 while (scanf("%d%d", &coefficientNum, &indexNum) != EOF)，可以判断是否输入到结束
    {
        if(indexNum == 0)  //形如9 8 7 0的情况
            cout <<"";
        else
            cout << ' ' << coefficientNum * indexNum << ' ' << indexNum - 1;
    }
    return 0;
}
