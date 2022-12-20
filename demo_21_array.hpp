/***
 * @Author: szf
 * @Date: 2022-12-20 17:44:10
 * @LastEditTime: 2022-12-20 18:26:12
 * @LastEditors: szf
 * @Description: myarrar
 * @FilePath: \Study-Code\demo_21_array.hpp
 * @@WeChat:szf13373959031
 */
#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyArray
{
public:
    MyArray(int capacity);

    MyArray(const MyArray &arr);

    MyArray &operator=(const MyArray &arr);

    void PushBack(const T &val);

    void PobBack();

    T &operator[](int index);

    int GetCapacity();

    int GetSize();

    void ShowArr();

    ~MyArray();

private:
    T *m_pAddress;
    int m_capacity;
    int m_size;
};

template <class T>
MyArray<T>::MyArray(int capacity)
{
    // cout << "MyArray 构造函数调用" << endl;
    this->m_capacity = capacity;
    this->m_size = 0;
    this->m_pAddress = new T[this->m_capacity];
}

template <class T>
MyArray<T>::MyArray(const MyArray &arr)
{
    // cout << "MyArray 拷贝构造函数调用" << endl;
    this->m_capacity = arr.m_capacity;
    this->m_size = arr.m_size;
    this->m_pAddress = new T[arr.m_capacity];

    for (int i = 0; i < this->m_size; i++)
    {
        this->m_pAddress[i] = arr.m_pAddress[i];
    }
}

template <class T>
MyArray<T> &MyArray<T>::operator=(const MyArray<T> &arr)
{
    // cout << "MyArray 等号运算符重载函数调用" << endl;
    if (this->m_pAddress != NULL)
    {
        delete[] this->m_pAddress;
        this->m_capacity = 0;
        this->m_size = 0;
    }
    this->m_capacity = arr.m_capacity;
    this->m_size = arr.m_size;
    this->m_pAddress = new T[arr.m_capacity];

    for (int i = 0; i < this->m_size; i++)
    {
        this->m_pAddress[i] = arr.m_pAddress[i];
    }

    return *this;
}

template <class T>
void MyArray<T>::PushBack(const T &val)
{
    if (this->m_capacity == m_size)
    {
        cout << "数组已满" << endl;
        return;
    }
    this->m_pAddress[this->m_size] = val;
    this->m_size++;
}

template <class T>
void MyArray<T>::PobBack()
{
    if (this->m_size == 0)
    {
        return;
    }
    this->m_size--;
}

template <class T>
T &MyArray<T>::operator[](int index)
{
    return this->m_pAddress[index];
}

template <class T>
int MyArray<T>::GetCapacity()
{
    return this->m_capacity;
}

template <class T>
int MyArray<T>::GetSize()
{
    return this->m_size;
}

template <class T>
void MyArray<T>::ShowArr()
{
    for (int i = 0; i < this->m_size; i++)
    {
        cout << this->m_pAddress[i] << endl;
    }
    cout << endl;
}

template <class T>
MyArray<T>::~MyArray()
{
    if (this->m_pAddress != NULL)
    {
        // cout << "MyArray 析构函数调用" << endl;
        delete[] this->m_pAddress;
        this->m_pAddress = NULL;
    }
}