#include "../../stdafx.h"
#include <iostream>

using namespace std;

class Product
{
public:
    virtual void Print()  = 0;
protected:
    Product() {};
};

class ProductA : public Product
{
public:
    virtual ~ProductA() {};
    ProductA() {};
    void Print() { cout << "ProductA" << endl; };
};

class ProductB : public Product
{
public:
    virtual ~ProductB() {};
    ProductB() {};
    void Print() { cout << "ProductB" << endl; };
};

class Factory
{
public:
    virtual ~Factory() {};
    Product * GetProductInstance(int tag)
    {
        switch (tag)
        {
        case 0:
            return new ProductA();
        case 1:
            return new ProductB();
        default:
            break;
        }
    }
};


class TestFactory
{
public:
    TestFactory()
    {
        Factory().GetProductInstance(0)->Print();
        Factory().GetProductInstance(1)->Print();
    }
};