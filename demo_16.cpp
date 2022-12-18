/***
 * @Author: szf
 * @Date: 2022-12-17 08:59:46
 * @LastEditTime: 2022-12-17 09:17:28
 * @LastEditors: szf
 * @Description: 多态——案例三——电脑组装
 * @FilePath: \Study-Code\demo_16.cpp
 * @@WeChat:szf13373959031
 */

#include <iostream>
#include <string>
using namespace std;

class CPU
{
public:
    virtual void Calculate() = 0;
};

class VideoCard
{
public:
    virtual void Display() = 0;
};

class Memory
{
public:
    virtual void Storage() = 0;
};

class Computer
{
public:
    Computer(CPU *cpu, VideoCard *vc, Memory *mem)
    {
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }
    ~Computer()
    {
        if(m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }

        if(m_vc != NULL)
        {
            delete m_vc;
            m_vc = NULL;
        }

        if(m_mem != NULL)
        {
            delete m_mem;
            m_mem = NULL;
        }
    }
    void DoWork()
    {
        m_cpu->Calculate();
        m_vc->Display();
        m_mem->Storage();
    }

private:
    CPU *m_cpu;
    VideoCard *m_vc;
    Memory *m_mem;
};

// Intel

class IntelCPU : public CPU
{
public:
    void Calculate()
    {
        cout << "Intel CPU 计算" << endl;
    }
};

class IntelVideoCard : public VideoCard
{
public:
    void Display()
    {
        cout << "Intel 显卡 显示" << endl;
    }
};

class INtelMemory : public Memory
{
public:
    void Storage()
    {
        cout << "Intel 内存条 储存" << endl;
    }
};

// lenovo

class LenovoCPU : public CPU
{
public:
    void Calculate()
    {
        cout << "Lenovo CPU 计算" << endl;
    }
};

class LenovoVideoCard : public VideoCard
{
public:
    void Display()
    {
        cout << "Lenovo 显卡 显示" << endl;
    }
};

class LenovoMemory : public Memory
{
public:
    void Storage()
    {
        cout << "Lenovo 内存条 储存" << endl;
    }
};

void Test01()
{
    CPU *intelcpu = new IntelCPU();
    VideoCard *intelvideocard = new IntelVideoCard();
    Memory *intelmemry = new INtelMemory();

    Computer * computer1 = new Computer(intelcpu, intelvideocard, intelmemry);
    computer1->DoWork();
    delete computer1;
}

void Test02()
{
    Computer * computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
    computer2->DoWork();
    delete computer2;
}

void Test03()
{
    Computer * computer3 = new Computer(new IntelCPU, new IntelVideoCard, new LenovoMemory);
    computer3->DoWork();
    delete computer3;
}

int main()
{
    Test01();
    cout << "-------------" << endl;
    Test02();
    cout << "-------------" << endl;
    Test03();

    system("pause");
    return 0;
}
