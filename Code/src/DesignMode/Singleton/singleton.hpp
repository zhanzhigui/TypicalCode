#include <iostream>

using namespace std;


class TestA 
{
public:
    TestA() : m_str("asdf") {}
    TestA(const string& str): m_str(str){ }

    void print()
    {
        cout<< m_str <<endl;
    }

    string m_str;
};

class TestB
{
public:
    TestB() { cout << "constrcut B" << endl; }

};

template <class T>
class SingleInstance
{
public:
    template <class... T2>
    static T* GetInstance(T2&&... args);
private:
    static T* t;
};

template <class T>
T* SingleInstance<T>::t = NULL;

template <class T>
template <class... T2>
T* SingleInstance<T>::GetInstance(T2&&... args)
{
    if (t == NULL)
    {
        t = new T(std::forward<T2>(args)...);
    }
    return t;
}

class TestSingleton 
{
public:
    TestSingleton()
    {
        cout<<"******* TestSingleton BEGIN *******"<<endl;
        int *p = SingleInstance<int>::GetInstance();
        //TestA * ptr = SingleInstance<TestA>::GetInstance();

        
        TestA * Pptr1 = SingleInstance<TestA>::GetInstance();
        TestA * ptr2 = SingleInstance<TestA>::GetInstance("test1");

        cout <<*p<<endl;
        //ptr->print();
        ptr2->print();
        cout<<"******* TestSingleton END *******"<<endl;
    }
};