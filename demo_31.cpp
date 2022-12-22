/***
 * @Author: szf
 * @Date: 2022-12-22 23:04:14
 * @LastEditTime: 2022-12-22 23:57:12
 * @LastEditors: szf
 * @Description: map / multimap
 * @FilePath: \Study-Code\demo_31.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

//* map
// 所有元素都是pair
// 第一个元素是key(键值),起到索引作用,第二个元素为value(实值)
// 所有元素都会根据元素键值自动排序
// map/multimap本质为关联式容器,底层结构是用二叉树实现

// 优点:可以根据key值快速找到value
// myltimap不允许容器中有重复key值元素
// multimap允许容器中有重复key值元素

//* 构造
// map<T1,T2> mp;
// map(const map &mp);

//* 赋值
// map& operator=(const map &mp);

//* 大小和交换
// size();
// empty();
// swap();

//* 插入和删除
// insert(elem);
// clear();
// erase(pos); //删除pos迭代器所指的元素,返回下一个元素的迭代器
// erase(beg, end); //删除区间[beg,end)的所有元素,返回下一个元素的迭代器
// erase(key); //删除容器中值为key的元素

//* 查找与统计
// find(key) //查找key是否存在,返回该键元素的迭代器,若不存在,返回set.end()
// count(key) //统计key的元素个数,返回整型

//* 排序
// 仿函数

class MyCompare
{
public:
    bool operator()(const int v1, const int v2) const
    {
        return v1 > v2;
    }
};

void PrintMap(const map<int, int> &m)
{
    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    if (m.empty())
    {
        cout << "map为空" << endl;
    }
    else
    {
        cout << "map的大小为 : " << m.size() << endl;
    }
    cout << endl;
}

void PrintMapSort(const map<int, int, MyCompare> &m)
{
    for (map<int, int, MyCompare>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    if (m.empty())
    {
        cout << "map为空" << endl;
    }
    else
    {
        cout << "map的大小为 : " << m.size() << endl;
    }
    cout << endl;
}

void Test01()
{
    // 构造
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(5, 50));
    PrintMap(m);

    map<int, int> m2(m);
    PrintMap(m2);

    map<int, int> m3;
    m3 = m2;
    PrintMap(m3);
}

void Test02()
{

    // 插入和交换
    map<int, int> m3;
    map<int, int> m4;
    m3.insert(pair<int, int>(1, 10));
    m3.insert(pair<int, int>(2, 10));
    m3.insert(pair<int, int>(3, 10));
    m4.insert(pair<int, int>(1, 50));
    m4.insert(pair<int, int>(2, 60));
    m4.insert(pair<int, int>(3, 70));
    m4.swap(m3);
    PrintMap(m3);
    PrintMap(m4);
}

void Test03()
{
    // 插入和删除
    map<int, int> m3;
    m3.insert(pair<int, int>(1, 10));
    m3.insert(pair<int, int>(2, 10));
    m3.insert(pair<int, int>(3, 10)); // 1
    m3.insert(make_pair(4, 10));
    m3.insert(make_pair(5, 20));                 // 2
    m3.insert(map<int, int>::value_type(6, 30)); // 3
    m3[7] = 40;                                  // 4
    PrintMap(m3);

    map<int, int>::iterator pos = m3.begin();
    pos = m3.erase(pos);
    pos = m3.erase(pos);
    pos = m3.erase(pos);
    pos = m3.erase(pos);
    PrintMap(m3);

    m3.erase(5);
    m3.erase(6);
    PrintMap(m3);

    m3.clear();
    PrintMap(m3);
}

void Test04()
{
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(4, 40));

    map<int, int>::iterator it = m1.find(1);
    PrintMap(m1);
}

void Test05()
{
    map<int, int, MyCompare> m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(4, 20));
    m1.insert(pair<int, int>(6, 30));
    m1.insert(pair<int, int>(3, 40));
    m1.insert(pair<int, int>(7, 10));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(8, 30));
    m1.insert(pair<int, int>(5, 40));
    m1.insert(pair<int, int>(9, 40));
    PrintMapSort(m1);
}

int main()
{
    // Test01();
    // Test03();
    // Test04();
    Test05();

    system("pause");
    return 0;
}
