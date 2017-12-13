// EnumToStringTester.cpp : Defines the entry point for the console application.
//
#pragma once
#ifndef GUDGE_ONE_FUNC_EXISTS_IN_CLASS_HPP
#define GUDGE_ONE_FUNC_EXISTS_IN_CLASS_HPP

#include "stdafx.h"
#include <iostream>
#include <map>

using namespace std;
// The one and only application object

class A
{
public:
    inline int has_depdendent_speed_type() const;
    bool les(const A& other);
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

class TestGudgeOneFunCExistInClass
{
public:
    TestGudgeOneFunCExistInClass()
    {
        int i = TypeExistEqualMemberFunc<A>::value1;
#if 1
        {
            cout<<"A "<<endl;
        }
#endif
        std::cout<< TypeExistEqualMemberFunc<A>::value1 <<std::endl;
        std::cout<< TypeExistEqualMemberFunc<B>::value1 <<std::endl;

        std::cout<< TypeExistEqualMemberFunc<A>::value2 <<std::endl;
        std::cout<< TypeExistEqualMemberFunc<B>::value2 <<std::endl;
    }
};

#endif

