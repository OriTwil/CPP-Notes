/***
 * @Author: szf
 * @Date: 2022-12-13 00:05:56
 * @LastEditTime: 2022-12-13 00:13:41
 * @LastEditors: szf
 * @Description: 引用
 * @FilePath: \Study-Code\demo_2.cpp
 * @@WeChat:szf13373959031
 */

#include <iostream>
using namespace std;

// 交换函数（引用作参数）

// 值传递
void mySwap01(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "mySwap01 in func a = " << a << endl;
    cout << "mySwap01 in func b = " << b << endl;
}
// 地址传递
void mySwap02(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// 引用传递
void mySwap03(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 引用作函数的返回值

// 1.不要返回局部变量的引用
//  int& test01()
//  {
//      int a = 10;
//      return a;//错误示范
//  }

// 2.函数调用可以作为左值
int &test02()
{
    static int a = 10;
    return a;
}

//打印函数（常量指针用于修饰形参，防止误操作）
void showValue(const int &val)
{
    // val = 1000;//防止函数内部修改数据
    cout << "val = " << val << endl;
}

int main()
{
    int a = 10;
    int &b = a; // 引用的基本语法，本质是给变量去别名

    // 引用的本质是一个指针常量
    //{int& ref = a 等价于 int* const ref = &a} {ref = 10 等价于 *ref = 20}

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    /*
    注意：引用必须初始化，一旦初始化，就不可以更改
    */
    int a1 = 20;

    mySwap01(a, a1);
    cout << "mySwap01 a = " << a << endl;
    cout << "mySwap01 a1 = " << a1 << endl; // 未交换

    mySwap02(&a, &a1);
    cout << "mySwap02 a = " << a << endl;
    cout << "mySwap02 a1 = " << a1 << endl; // 交换

    mySwap03(a, a1);
    cout << "mySwap03 a = " << a << endl;
    cout << "mySwap03 a1 = " << a1 << endl; // 交换

    /*
    引用作函数的返回值
    */

    int &ref = test02();
    cout << "ref = " << ref << endl;
    cout << "test02 = " << test02() << endl;

    test02() = 1000;
    cout << "ref = " << ref << endl;
    cout << "test02 = " << test02() << endl;

    ref = 2000;
    cout << "ref = " << ref << endl;
    cout << "test02 = " << test02() << endl;

    //常量引用作形参
    const int& ref = 10;//编译器优化代码，自动开辟一个空间
    showValue(a);

    system("pause");
    return 0;
}