// EnumToStringTester.cpp : Defines the entry point for the console application.
//
#pragma once
#ifndef GUDGE_ONE_FUNC_EXISTS_IN_CLASS_HPP
#define GUDGE_ONE_FUNC_EXISTS_IN_CLASS_HPP

//#include "stdafx.h"
#include <iostream>
#include <map>

using namespace std;
// The one and only application object

class A
{
public:
    inline int type()  {cout<<"A type"<<endl; return 1;};
    bool les(const A& other) {return false;};
    int point()  {return 1;};
};

class B
{
public:
    bool les(const B& other);
};

template<class T>
struct TypeExistEqualMemberFunc
{
    static void has_depdendent_speed_type();
    static void les();
    struct test: T
    {
        static bool f(bool (T::*)(const T&));
        static int f(int (T::*)()const);
        static char f(...);
        enum {value1 = (sizeof(f(&has_depdendent_speed_type)) == sizeof(int))};
        enum {value2 = (sizeof(f(&les)) == sizeof(int))};
    };

    enum {value1 = test::value1};
    enum {value2 = test::value2};
};

template <class T>
class RegistPFunc 
{
public:
    T a;
    RegistPFunc(T a_)
    {
        a = a_;
        get_type = &A::type;
    }

    int (T::*get_type)();
    int (T::*get_point)();
    void funct()
    {
        cout<<"asdf"<<enld;
    }
};

class TestGudgeOneFunCExistInClass
{
public:
    TestGudgeOneFunCExistInClass()
    {
        cout<<"******* TestGudgeOneFunCExistInClass BEGIN *******"<<endl;
        int i = TypeExistEqualMemberFunc<A>::value1;
        A a;
        RegistPFunc<A> reg(a);
        //reg.*get_type();
           
        A aa;
        int (A::*p)() = &A::type;
        cout<< (aa.*p)() <<endl;
     
        
        //std::cout<< TypeExistEqualMemberFunc<A>::value1 <<std::endl;
        //std::cout<< TypeExistEqualMemberFunc<B>::value1 <<std::endl;

        //std::cout<< TypeExistEqualMemberFunc<A>::value2 <<std::endl;
        //std::cout<< TypeExistEqualMemberFunc<B>::value2 <<std::endl;
        cout<<"******* TestGudgeOneFunCExistInClass END *******"<<endl;
    }
};

#endif

