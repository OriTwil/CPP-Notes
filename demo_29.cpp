/***
 * @Author: szf
 * @Date: 2022-12-22 16:00:09
 * @LastEditTime: 2022-12-22 16:01:29
 * @LastEditors: szf
 * @Description: list 链表容器
 * @FilePath: \Study-Code\demo_29.cpp
 * @@WeChat:szf13373959031
 */

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

//* 链表
// 方便插入元素,删除元素,但遍历速度慢

//* list
// list和vector是STL里最常用的元素

//* 成员类型
// value_type	                T
// allocator_type	            Allocator
// size_type	                无符号整数类型（通常是 std::size_t ）
// difference_type	            有符号整数类型（通常是 std::ptrdiff_t ）
// reference	                value_type&
// const_reference	            const value_type&
// pointer	                    value_type*
// const_pointer	            const value_type*
// iterator	                    指向 value_type 的双向迭代器
// const_iterator	            指向 const value_type 的双向迭代器
// reverse_iterator	            std::reverse_iterator
// const_reverse_iterator	    std::reverse_iterator<const_iterator>

//* 构造函数
// list();	                                        默认构造函数。构造拥有默认构造的分配器的空容器
// list( size_type count,const T& value);	        构造拥有 count 个有值 value 的元素的容器。
// explicit list( size_type count );	            构造拥有个 count 默认插入的 T 实例的容器。
// list( InputIt first, InputIt last, const Allocator& alloc = Allocator() );	构造拥有范围 [first, last) 内容的容器。
// list( const list& other );	                    拷贝构造函数。构造拥有 other 内容的容器。

//* 赋值
// list& operator=( const list& other );	        复制赋值运算符。以 other 的副本替换内容。
// list& operator=( std::initializer_list ilist );	以 initializer_list ilist 所标识者替换内容。
// void assign( size_type count, const T& value );	以 count 份 value 的副本替换内容。
// template< class InputIt >
// void assign( InputIt first, InputIt last );	    以范围 [first, last) 中元素的副本替换内容。
// void assign( std::initializer_list ilist );

//* 元素访问
// reference front();	            返回到容器首元素的引用。
// const_reference front() const;	返回到容器首元素的引用。
// reference back();	            返回到容器中最后一个元素的引用。
// const_reference back() const;	返回到容器中最后一个元素的引用。
// 不能[]

//* 容量
// bool empty() const;	        检查容器是否无元素，即是否 begin() == end() 。
// size_type size() const;	    返回容器中的元素数，即 std::distance(begin(), end()) 。
// size_type max_size() const;	返回根据系统或库实现限制的容器可保有的元素最大数量，即对于最大容器的 std::distance(begin(), end()) 。

//* 修改
// void clear();	    从容器擦除所有元素。此调用后 size() 返回零。
// iterator insert( iterator pos, const T& value );	在 pos 前插入 value 。
// void insert( iterator pos, size_type count, const T& value );	在 pos 前插入 value 的 count 个副本。
// template< class InputIt >
// void insert( iterator pos, InputIt first, InputIt last);	在 pos 前插入来自范围 [first, last) 的元素
// iterator insert( const_iterator pos, std::initializer_list ilist );	在 pos 前插入来自 initializer_list ilist 的元素
// iterator erase( iterator pos );	移除位于 pos 的元素。
// iterator erase( iterator first, iterator last );	移除范围 [first; last) 中的元素。
// void pop_back();	移除容器的末元素。
// void push_front( const T& value );	前附给定元素 value 到容器起始。
// void push_back( const T& value );	后附给定元素 value 到容器尾。
// void pop_front();	移除容器首元素。
// void resize( size_type count );	重设容器大小以容纳 count 个元素。
// void resize( size_type count, T value = T() );	count - 容器的大小，value - 用以初始化新元素的值
// void swap( list& other );	将内容与 other 的交换。

//* 操作
// void merge( list& other );	归并二个已排序链表为一个。链表应以升序排序。
// void splice( const_iterator pos, list& other );	从 other 转移所有元素到 *this 中。元素被插入到 pos 所指向的元素之前。操作后容器 other 变为空。
// void splice( const_iterator pos, list& other, const_iterator it );	从 other 转移 it 所指向的元素到 *this 。元素被插入到 pos 所指向的元素之前。
// void splice( const_iterator pos, list& other, const_iterator first, const_iterator last);	从 other 转移范围 [first, last) 中的元素到 *this 。元素被插入到 pos 所指向的元素之前。
// void remove( const T& value );	移除所有满足特定标准的元素。value - 要移除的元素的值
// void reverse();	逆转容器中的元素顺序。
// void unique();	从容器移除所有相继的重复元素。只留下相等元素组中的第一个元素。
// void sort();	以升序排序元素。保持相等元素的顺序。用 operator< 比较元素
// template< class Compare >
// void sort( Compare comp );	以升序排序元素。保持相等元素的顺序。用给定的比较函数 comp 。

//* 迭代器
// iterator begin();	返回指向 list 首元素的迭代器。
// 若 list 为空，则返回的迭代器将等于 end() 。
// const_iterator begin() const;	返回指向 list 首元素的迭代器。
// 若 list 为空，则返回的迭代器将等于 end() 。
// iterator end();	返回指向 list 末元素后一元素的迭代器。
// const_iterator end() const;	返回指向 list 末元素后一元素的迭代器。
// reverse_iterator rbegin();	返回指向逆向 list 首元素的逆向迭代器。
// const_reverse_iterator rbegin() const;	返回指向逆向 list 首元素的逆向迭代器。
// reverse_iterator rend();	返回指向逆向 list 末元素后一元素的逆向迭代器。
// const_reverse_iterator rend() const;	返回指向逆向 list 末元素后一元素的逆向迭代器。

bool MyCompare(int v1, int v2)
{
    return v1 > v2;
}

void PrintList(const list<int> &l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void Test01()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    l1.push_back(50);
    PrintList(l1);

    list<int> l2(l1.begin(), l1.end());
    PrintList(l2);

    list<int> l3(l2);
    PrintList(l3);

    list<int> l4(10, 100);
    PrintList(l4);
}

void Test02()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    l1.push_back(50);
    PrintList(l1);

    list<int> l2;
    l2 = l1;
    PrintList(l2);

    list<int> l3;
    l3.assign(l2.begin(), l2.end());
    PrintList(l3);

    list<int> l4(10, 300);
    l4.swap(l3);
    PrintList(l3);

    cout << "l1的首元素为 : " << l1.front() << endl;
    cout << "l1的最后一个元素为 : " << l1.back() << endl;
}

void Test03()
{
    list<int> l1;
    l1.push_back(20);
    l1.push_back(50);
    l1.push_back(60);
    l1.push_back(40);
    l1.push_back(30);
    l1.push_back(10);
    l1.push_back(70);
    PrintList(l1);

    // 不支持随机访问迭代器的容器,不可以用标准算法,内部会提供相应算法
    l1.sort();
    l1.sort(MyCompare); // 按自定义排序方式
    PrintList(l1);

    list<int>::iterator it = l1.begin();
    it++;
    it--;
    // it = it + 1; //不能随机访问
    cout << "l1的第一个元素" << *it << endl;

    l1.reverse();
    cout << "l1的第一个元素" << l1.front() << endl;
}

int main()
{
    // Test01();
    // Test02();
    Test03();

    system("pause");
    return 0;
}
