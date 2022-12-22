/***
 * @Author: szf
 * @Date: 2022-12-22 11:19:55
 * @LastEditTime: 2022-12-22 11:30:18
 * @LastEditors: szf
 * @Description: deque
 * @FilePath: \Study-Code\demo_25.cpp
 * @@WeChat:szf13373959031
 */

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

//* deque

// 双端数组
// 对头部插入删除速度比vector快
// vector访问元素速度较快

//* (1)构造函数

// deque():创建一个空deque
// vector(v.begin(),v.end());
// deque(int nSize):创建一个deque,元素个数为nSize
// deque(int nSize,const T& t):创建一个deque,元素个数为nSize,且值均为t
// deque(const deque &):拷贝构造函数

//* (2)增加函数

// void push_front(const T& x):双端队列头部增加一个元素X
// void push_back(const T& x):双端队列尾部增加一个元素x
// iterator insert(iterator it,const T& x):双端队列中某一元素前增加一个元素x
// void insert(iterator it,int n,const T& x):双端队列中某一元素前增加n个相同的元素x
// void insert(iterator it,const_iterator first,const_iteratorlast):双端队列中某一元素前插入另一个相同类型向量的[forst,last)间的数据

//* (3)删除函数

// Iterator erase(iterator it):删除双端队列中的某一个元素
// Iterator erase(iterator first,iterator last):删除双端队列中[first,last）中的元素
// void pop_front():删除双端队列中最前一个元素
// void pop_back():删除双端队列中最后一个元素
// void clear():清空双端队列中最后一个元素

//* (4)遍历函数

// operator[];
// reference at(int pos):返回pos位置元素的引用
// reference front():返回首元素的引用
// reference back():返回尾元素的引用
// iterator begin():返回向量头指针，指向第一个元素
// iterator end():返回指向向量中最后一个元素下一个元素的指针（不包含在向量中）
// reverse_iterator rbegin():反向迭代器，指向最后一个元素
// reverse_iterator rend():反向迭代器，指向第一个元素的前一个元素

//* (5)判断函数

// bool empty() const:向量是否为空，若true,则向量中无元素

//* (6)大小函数

// Int size() const:返回向量中元素的个数
// int max_size() const:返回最大可允许的双端对了元素数量值
// resize(num);
// resize(num,elem);

//* (7)其他函数

// void swap(deque&):交换两个同类型向量的数据
// void assign(int n,const T& x): 向量中第n个元素的值设置为x
// deque& operator=(const deque&deq) // 重载=运算符赋值
// void assign(beg,end) //将beg到end区间的数据拷贝

// sort(iterator beg,iterator end) //区间排序

void PrintDeque(const deque<int> &q)
{
    for (deque<int>::const_iterator it = q.begin(); it != q.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl; 
    cout << "q的大小为 : " << q.size() << endl;
    cout << endl;
}
void Test01()
{
    deque<int> q1;
    for (int i = 0; i < 10; i++)
    {
        q1.push_back(i);
    }
    PrintDeque(q1);

    deque<int> q2(q1.begin(), q1.end() - 5);
    PrintDeque(q2);

    deque<int> q3;
    q3.assign(10, 100);
    q3.resize(15,200);
    PrintDeque(q3);
}

void Test03()
{
    deque<int> q1;

    q1.push_back(5);
    q1.push_back(1);
    q1.push_back(2);
    q1.push_back(6);
    q1.push_back(3);
    q1.push_back(4);
    q1.push_back(9);
    q1.push_back(7);
    q1.push_back(8);

    PrintDeque(q1);

    sort(q1.begin(),q1.end());
    PrintDeque(q1);
}

int main()
{
    // Test01();
    Test03();

    system("pause");
    return 0;
}