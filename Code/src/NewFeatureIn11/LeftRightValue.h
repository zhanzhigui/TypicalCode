#pragma once
#include <iostream>

void Swap(int& a, int& b)
{

}

void Swap( int&& a,   int&& b)
{
    
}

int& getRightVaue()
{
    int i = 1;
    cout << &i << endl;
    return i;
}

string getRightVaue1()
{
    string ii = "1";
    cout << &ii << endl;
    return ii;
}

class TestLeftRightValue
{
public:
    TestLeftRightValue()
    {
        Swap(1, 2);
        double a = 1.0;
        double b = 2.0;
        //Swap(a, b);
        //Swap((int)a, (int)b);

        int& var = getRightVaue();
        cout << var << endl;
        cout << &var << endl;
        std::cout << var << endl;
        string&& var1 = getRightVaue1();
        cout << &var1 << endl;
        string var2 = getRightVaue1();
        cout << &var2 << endl;
        std::cout << var << endl;
        std::cout << var1 << endl;
        var = 2;
        cout << &var << endl;
        cout << var << endl;
        cout << getRightVaue1() << endl;
    }
};