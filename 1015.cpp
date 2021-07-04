#include <iostream>
#include <algorithm>  //sort()需要的头文件

using namespace std;

//显然考生信息是按照准考证号-德分-才分的规律录入的，因此使用类或者结构体会显得直观且便利

class information{
    public:
        int num;
        int morality;
        int talent;
};

/*接下来定义sort()的排序规则
如果未定义cmp()，则sort()默认升序

bool cmp(int a,int b)      
{                          //要想实现降序，只需要改变一个符号即可 
	return a < b;          //   return a > b;
}                          
*/

bool cmp(information info1, information info2)
{
    if(info1.morality+info1.talent == info2.morality+info2.talent)
    {
        if(info1.morality == info2.morality)
            return info1.num < info2.num;
        else
            return info1.morality > info2.morality;
    }
    else
        return info1.morality + info1.talent > info2.morality + info2.talent;
}

int main()
{
    int N, L, H;
    cin >> N >> L >> H;
    int count1,count2,count3,count4,i;
    count1 = count2 = count3 = count4 = 0;

/*由题目可得，所有过线L的考生被分为四个等级，且过线+不过线的考生总数为N
因此使用new-delete按照输入的N来动态分配内存
从输入流中逐个读取准考证号-德分-才分，再分到四个等级中*/

    information* grade1 = new information[N];
    information* grade2 = new information[N];
    information* grade3 = new information[N];
    information* grade4 = new information[N];
    information temp;

    for (i = 0; i < N;i++)
    {
        cin >> temp.num >> temp.morality >> temp.talent;
        if(temp.morality < L || temp.talent < L)
            continue;
        else if(temp.morality >= H && temp.talent >= H)
        {
            grade1[count1] = temp;
            count1++;
        }
        else if(temp.morality >= H && temp.talent < H)
        {
            grade2[count2] = temp;
            count2++;
        }
        else if(temp.morality< H && temp.talent < H && temp.morality >= temp.talent)
        {
            grade3[count3] = temp;
            count3++;
        }
        else
        {
            grade4[count4] = temp;
            count4++;
        }
    }

    cout << count1 + count2 + count3 + count4 << endl;
    sort(grade1, grade1 + count1, cmp);
    for (i = 0; i < count1;i++)
        cout << grade1[i].num << ' ' << grade1[i].morality << ' ' << grade1[i].talent << endl;
    sort(grade2, grade2 + count2, cmp);
    for (i = 0; i < count2;i++)
        cout << grade2[i].num << ' ' << grade2[i].morality << ' ' << grade2[i].talent << endl;
    sort(grade3, grade3 + count3, cmp);
    for (i = 0; i < count3;i++)
        cout << grade3[i].num << ' ' << grade3[i].morality << ' ' << grade3[i].talent << endl;
    sort(grade4, grade4 + count4, cmp);
    for (i = 0; i < count4;i++)
        cout << grade4[i].num << ' ' << grade4[i].morality << ' ' << grade4[i].talent << endl;
    delete[] grade1;
    delete[] grade2;
    delete[] grade3;
    delete[] grade4;
    
/*new了几个，一定要delete几个

用new-delete对数组进行动态分配的格式为
    指针变量名=new 类型名[下标表达式];
    delete[ ] 指向该数组的指针变量名;
如果delete语句中少了方括号，编译器会认为该指针是指向数组第一个元素的指针，会产生回收不彻底的问题（只回收了第一个元素所占空间）
加了方括号后就转化为指向数组的指针，回收整个数组*/
}
