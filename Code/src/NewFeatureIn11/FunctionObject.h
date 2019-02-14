#include <stdint.h>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

class StringSort {
public:
    bool operator() (const string &str1, const string &str2) const
    {
        return str1 > str2;
    }
};

class NoLess
{
public:
    NoLess(int min = 0) :m_min(min) {}
    bool operator() (int value) const
    {
        return value >= m_min;
    }
private:
    int m_min;
};

template <class T1, class T2>
class NoLess1
{
public:
    NoLess1(T2 min = 0) :m_min(min) {}
    bool operator() (T1 value) const
    {
        return value >= m_min;
    }
    T2 m_min;
};

class TestFunctionObject
{
public:
    void intit()
    {
        cout << "asdf" << endl;
    }

    TestFunctionObject()
    {
        cout << "******* TestSingleton BEGIN *******" << endl;
        set<string, StringSort> myset;
        myset.insert("A");
        myset.insert("B");
        myset.insert("C");
        cout << *myset.begin() << endl;

        vector<int> myvec;
        myvec.push_back(1);
        myvec.push_back(2);
        myvec.push_back(10);
        remove_if(myvec.begin(), myvec.end(), NoLess(3));

        cout << "******* TestSingleton END *******" << endl;
    }
};