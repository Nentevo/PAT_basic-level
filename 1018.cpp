#include <iostream>

using namespace std;

void DisplayMostCJBWin(int Ccount, int Jcount, int Bcount);  
/*因为最后甲乙两人都要输出获胜最多的手势，为避免重复，故利用函数
同时函数返回值不能是字符，为方便起见，函数内部直接输出字符
*/

int main()
{
    int N, i;
    char A, B;
    int ACcount=0, AJcount=0, ABcount=0,BCcount=0, BJcount=0, BBcount=0, Awin=0, Bwin=0;

    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> A >> B;  //因为结果输出与原本输入数据无关，因此没有使用数组，直接一边从输入流中读入、一边处理
        if(A=='C')  //不需要考虑平局的情况，因为甲乙两方的平局数一定相等，总局数-甲方获胜数-乙方获胜数就是平局数
        {
            if(B=='J')
            {
                ACcount++;
                Awin++;
            }
            else if(B=='B')
            {
                BBcount++;
                Bwin++;
            }
        }
        else if(A=='J')
        {
            if(B=='B')
            {
                AJcount++;
                Awin++;
            }
            else if(B=='C')
            {
                BCcount++;
                Bwin++;
            }
        }
        else
        {
            if(B=='C')
            {
                ABcount++;
                Awin++;
            }
            else if(B=='J')
            {
                BJcount++;
                Bwin++;
            }
        }
    }
    cout << Awin << ' ' << N-Awin-Bwin << ' ' << Bwin << endl;
    cout << Bwin << ' ' << N-Awin-Bwin << ' ' << Awin << endl;

    DisplayMostCJBWin(ACcount, AJcount, ABcount);
    cout << ' ';
    DisplayMostCJBWin(BCcount, BJcount, BBcount);
    cout << endl;
    return 0;
}

void DisplayMostCJBWin(int Ccount, int Jcount, int Bcount)
{
    if(Bcount >= Ccount && Bcount >= Jcount)
        cout << 'B';
    else if(Ccount > Bcount && Ccount >= Jcount)
        cout << 'C';
    else if(Jcount > Bcount && Jcount > Ccount)
        cout << 'J';
    return; //函数类型为void，返回可以不写，也可以写return;
}
