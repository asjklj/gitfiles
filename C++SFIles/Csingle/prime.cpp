// //1、 死扣定义的方式
// // 时间复杂度为O(n)
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     int i;
//     cin >> n;
//     if (n <= 1)
//         cout << "no" << endl;
//     else if (n == 2)
//         cout << "yes" << endl;
//     else
//     {
//         for (i = 2; i < n; i++)
//         {
//             if (n % i == 0)
//             {
//                 cout << "no" << endl;
//                 break;
//             }
//         }
//         if (i == n)
//             cout << "yes" << endl;
//     }
//     system("pause");
// }

// // 2、优化：1、先解决1和2的情况然后排除所有的偶数
// // 2、并且发现搜索范围并不需要为n，只需要为sqrt(n)(若存在>sqrt(n)的因子，则必有<sqrt(n)的与之对应的因子)
// // 时间复杂度为O(sqrt(n))
// #include <iostream>
// #include <cmath>
// using namespace std;
// int main()
// {
//     int n;
//     int i;
//     bool flag = false;
//     cin >> n;

//     if (n <= 1)
//         flag = false;
//     else if (n == 2)
//         flag = true;
//     else
//     {
//         for (i = 2; i <= sqrt(n); i++)
//         {
//             if (n % i == 0)
//             {
//                 flag = false;
//                 break;
//             }
//         }
//         if (i > sqrt(n))
//             flag = true;
//     }
//     if (flag)
//         cout << "yes" << endl;
//     else
//         cout << "no" << endl;
//     system("pause");
// }

// 3、再优化：发现从5开始，6k,6k+1,6k+2,6k+3,6k+4,6k+5(k为正整数)中只有6k+1和6k+5可能为素数，故可以将循环的步长改为6
// 时间复杂度仍为O(sqrt(n))，但是运算速度加快，运行时间减少
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    int i;
    bool flag = false;
    cin >> n;

    if (n <= 1 || n == 4)
        flag = false;
    else if (n == 2 || n == 3)
        flag = true;
    else if (n % 6 != 5 && n % 6 != 1)
        flag = false;
    else
    {
        for (i = 5; i <= sqrt(n); i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
            {
                flag = false;
                break;
            }
        }
        if (i > sqrt(n))
            flag = true;
    }
    if (flag)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}