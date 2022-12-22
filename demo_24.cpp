/***
 * @Author: szf
 * @Date: 2022-12-21 22:15:09
 * @LastEditTime: 2022-12-21 22:16:05
 * @LastEditors: szf
 * @Description: vector
 * @FilePath: \Study-Code\demo_24.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <vector>
using namespace std;

//* vector
// vector也称为单端数组
// vector可以动态扩展,数组是静态空间
// 动态扩展不是原空间之后续借新空间,而是找更大的内存空间,然后将原数据拷贝新空间,释放原空间

//* vector构造函数
//  vector<T> v; //利用模板实现类实现,默认构造函数
//  vector(v.begin(),v.end()); //将区间中的元素拷贝给本身
//  vector(n,elem); // 构造函数将n个elem拷贝给本身
//  vector(const vecter &vec);//拷贝构造

//* vector赋值
// vector& operator=(const vector &vec);
// assign(beg,end);
// assign(n,elem)

//* vector容器和大小
// empty(); //判断容器是否为空
// capacity();
// size();
// resize(int num); //重新指定容器的长度为num,若容器边长,则以默认值填充新位置;若容器长度变短,则末尾超出容器长度元素删除
// resize(int num,elem) //填充多余位置elem

//* vector插入和删除
// push_back(ele); //尾部插入元素ele
// pop_back(); //删除最后一个元素
// insert(const_iterator pos, ele); //迭代器指向位置pos插入元素ele
// insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele
// erase(const_iterator pos); //删除迭代器指向的元素
// erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
// clear(); //删除容器中所有元素

//* vector数据存取
// at(int idx); //返回索引idx所指的数据
// operator[]; //返回索引idx所指的数据
// front(); //返回容器中第一个数据元素
// back(); //返回容器中最后一个数据元素

//* vector互换容器
// swap(vac);
// 巧用swap可以收缩内存空间
//* vector预留空间
// reserve(int len);

void PrintVector(vector<int> &v)
{
    cout << "v1为\t   : ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "v的容量为 : " << v.capacity() << endl;
    cout << "v的大小为 : " << v.size() << endl;
    cout << endl;
}

void Test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    PrintVector(v1);

    vector<int> v2(v1.begin(), v1.end());
    PrintVector(v2);

    vector<int> v3(10, 100);
    PrintVector(v3);

    vector<int> v4(v3);
    PrintVector(v4);
}

void Test02()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    vector<int> v2;
    v2 = v1;
    PrintVector(v2);

    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    PrintVector(v2);

    vector<int> v4;
    v4.assign(10, 100);
    PrintVector(v4);
}

void Test03()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    if (v1.empty())
    {
        cout << "v1为空" << endl;
    }
    else
    {
        cout << "v1不为空" << endl;
        PrintVector(v1);
    }

    v1.resize(15, 20);
    PrintVector(v1);

    v1.resize(5, 10);
    PrintVector(v1);
}

void Test04()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    PrintVector(v1);

    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    PrintVector(v1);

    v1.insert(v1.begin(), 100);
    PrintVector(v1);

    v1.insert(v1.begin(), 5, 100);
    PrintVector(v1);

    v1.erase(v1.begin() + 10);
    PrintVector(v1);

    v1.erase(v1.begin(), v1.end());
    PrintVector(v1);
}

void Test05()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    cout << v1[0]
         << v1.at(1) << endl;
    cout << "第一个元素 : " << v1.front() << endl
         << "最后一个元素 : " << v1.back();
}

void Test06()
{
    vector<int> v1(10, 1);
    vector<int> v2(10, 2);
    PrintVector(v1);
    PrintVector(v2);

    v1.swap(v2);
    PrintVector(v1);
    PrintVector(v2);

    vector<int> v3;
    for (int i = 0; i < 100; i++)
    {
        v3.push_back(1);
    }
    PrintVector(v3);

    v3.resize(3);
    PrintVector(v3);

    vector<int>(v3).swap(v3); // 收缩容器:拷贝构造一个匿名对象,与v3交换
    PrintVector(v3);
}

void Test07()
{
    int num = 0;
    int *p = NULL;
    vector<int> v1;

    // v1.reserve(100);
    
    for (int i = 0; i < 100; i++)
    {
        v1.push_back(i);

        if (p != &v1[0])
        {
            p = &v1[0];
            num++;
        }
    }// 高级~
    cout << "新开辟了" << num << "次内存" << endl;

}

int main()
{
    // Test01();
    // Test02();
    // Test03();
    // Test04();
    // Test05();
    // Test06();
    Test07();

    system("pause");
    return 0;
}
