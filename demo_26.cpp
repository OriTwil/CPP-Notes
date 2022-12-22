/***
 * @Author: szf
 * @Date: 2022-12-22 13:54:37
 * @LastEditTime: 2022-12-22 13:59:39
 * @LastEditors: szf
 * @Description: STL案例仿真1--评委打分
 * @FilePath: \Study-Code\demo_26.cpp
 * @@WeChat:szf13373959031
 */

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
using namespace std;

class Person
{
public:
    Person(string name, int score)
    {
        this->m_name = name;
        this->m_score = score;
    }

public:
    string m_name;
    int m_score;
};

void CreatePerson(vector<Person> &v)
{
    string nameseed = "ABCDE";
    int num = 0;
    // cout << "请输入参赛选手总数 : ";
    // cin >> num;
    // cout << endl;

    for (int i = 0; i < 5; i++)
    {
        string name = "选手";
        // name += nameseed[i];
        name.append("ABCDE",i,1);
        int score = 0;

        Person person(name, score);
        v.push_back(person);
    }
}

void SetScore(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        deque<int> deq;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60;
            deq.push_back(score);
        }

        sort(deq.begin(), deq.end());
        deq.pop_back();
        deq.pop_front();

        // cout << it->m_name << "打分为 : ";
        // for (deque<int>::iterator dit = deq.begin(); dit != deq.end(); dit++)
        // {
        //     cout << *dit << " ";
        // }
        // cout << endl;

        int sum = 0;
        for (deque<int>::iterator dit = deq.begin(); dit != deq.end(); dit++)
        {
            sum += (*dit);
        }
        float avg = sum / deq.size();
        it->m_score = avg;
    }
}

void ShowScore(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名 : " << it->m_name << " 分数 : " << it->m_score << endl;
    }
}

int main()
{
    vector<Person> p;
    srand((unsigned int)time(nullptr));

    CreatePerson(p);
    SetScore(p);
    ShowScore(p);

    system("pause");
    return 0;
}
