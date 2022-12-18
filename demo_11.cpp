/***
 * @Author: szf
 * @Date: 2022-12-15 01:49:05
 * @LastEditTime: 2022-12-15 01:59:39
 * @LastEditors: szf
 * @Description: 继承
 * @FilePath: \Study-Code\demo_11.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
using namespace std;

// 继承方式
// class 子类：继承方式 父类，继承方式 父类

// 继承中的对象模型
// 父类中所谓非静态成员属性都会被子类继承
// 私有成员属性被隐藏，但确实被继承了

// 继承中的构造和析构顺序
/*
Base 的构造函数
Son  的构造函数
Son  的析构函数
Base 的析构函数
*/

// 继承同名成员处理方式
/*
    对父类中同名的成员，编译器会隐藏，如果要调用，需要加作用域
*/

// 继承中的同名静态成员的处理方式

// 菱形继承
// 两个派生类继承同一个基类
// 一个派生类再继承这两个派生类
// 两个父类拥有相同数据，需要加以作用域区分
// 数据重复会造成浪费，利用虚继承解决
// class 子类：virtual 继承方式 父类，virtual 继承方式 父类 

class BasePage // 基类（父类）：把重复的内容
{
public:
    BasePage()
    {
        m_a = 0;
        cout << "Base 的构造函数" << endl;
    }
    ~BasePage()
    {
        cout << "Base 的析构函数" << endl;
    }

public:
    void header()
    {
        cout << "公共头部" << endl;
    }

    void footer()
    {
        cout << "公共底部" << endl;
    }

    void left()
    {
        cout << "公共分类列表" << endl;
    }

public:
    int m_a;
    static int m_A;

protected:
    int m_b;

private:
    int m_c;
};
int BasePage::m_A = 0;

class Java : public BasePage // 子类（派生类）
{
public:
    void content()
    {
        cout << "Java视频" << endl;
    }
};

class Python : public BasePage
{
public:
    void content()
    {
        cout << "Python视频" << endl;
    }
};

class CPP : public BasePage
{
public:
    void content()
    {
        cout << "C++视频" << endl;
    }
};

class SonPage : public BasePage
{
public:
    SonPage()
    {
        cout << "Son的构造函数" << endl;
    }
    ~SonPage()
    {
        cout << "Son的析构函数" << endl;
    }

public:
    int m_a;
    int m_d;
    static int m_A;
};
int SonPage::m_A = 1;

void Test01()
{
    cout << "Java页面为:" << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();

    cout << "-------------" << endl;
    cout << "Python页面为:" << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();

    cout << "-------------" << endl;
    cout << "C++页面为:" << endl;
    CPP cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
}

void Test02()
{
    SonPage son1;
    cout << sizeof(son1) << endl;
}
void Test03()
{
    SonPage son1;
    son1.m_a = 100;
    cout << son1.m_a << " " << son1.BasePage::m_a << endl;
}
void Test04()
{
    SonPage son1;

    cout << "---------" << endl;
    cout << "通过对象访问" << endl;
    cout << "Son : " << son1.m_A << endl;
    cout << "Bace: " << son1.BasePage::m_A << endl;
    cout << "---------" << endl;
    cout << "通过类名访问" << endl;
    cout << "Son : " << SonPage::m_A << endl;
    cout << "Bace: " << BasePage::BasePage::m_A << endl;
    cout << "---------" << endl;
}
int main()
{
    // Test01();
    // Test02();
    // Test03();
    Test04();

    system("pause");
    return 0;
}
