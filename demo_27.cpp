/***
 * @Author: szf
 * @Date: 2022-12-22 14:49:49
 * @LastEditTime: 2022-12-22 14:52:08
 * @LastEditors: szf
 * @Description: stack 栈容器
 * @FilePath: \Study-Code\demo_27.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <stack>
using namespace std;

//* stack
// stack 是一种先进后出的数据结构,只有一个出口
// 栈底\栈顶

//* 构造
// stack<T> stk;
// stack(const stack& stk); //拷贝构造

//* 赋值
// 重载等号操作符

//* 存取
// q.push(x);		//将x压入栈顶
// q.top();		    //返回栈顶的元素
// q.pop();		    //删除栈顶的元素

//* 大小
// q.size();		//返回栈中元素的个数
// q.empty();		//检查栈是否为空,若为空返回true,否则返回false

void Test01()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "栈顶元素为:" << s.top() << endl;
    cout << "栈的大小 : " << s.size() << endl;

    while(!s.empty())
    {
        s.pop();
    }
    cout << "栈的大小 : " << s.size() << endl; 
}

int main()
{
    Test01();

    system("pause");
    return 0;
}