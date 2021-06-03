#include <iostream>

using namespace std;

int main()
{
    int n,i;
    long A, B, C;  //int表示范围[-2^31, 2^31-1]，不满足题目要求，需要用long
    cin >> n;
    for (i = 0; i < n;i++)
    {
        cin >> A >> B >> C;
        if(A+B>C)
            cout << "Case #" << i + 1 << ": true" << endl;
        else
            cout << "Case #" << i + 1 << ": false" << endl;
    }
}
