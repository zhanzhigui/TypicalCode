#ifndef ENUM_TO_STRING_HPP
#define ENUM_TO_STRING_HPP

#include "../stdafx.h"

using namespace std;
#undef DECL_ENUM_ELEMENT
#undef BEGIN_ENUM
#undef END_ENUM

#define DECL_ENUM_ELEMENT( Element ) Element
#define BEGIN_ENUM( ENUM_NAME ) typedef enum tag##ENUM_NAME 
#define END_ENUM( ENUM_NAME ) ENUM_NAME;

#define WEEK_DAY_ELEMENT \
    DECL_ENUM_ELEMENT(MIN_DAY), \
    DECL_ENUM_ELEMENT(Sun), \
    DECL_ENUM_ELEMENT(Mon),\
    DECL_ENUM_ELEMENT(Tue),\
    DECL_ENUM_ELEMENT(Wen),\
    DECL_ENUM_ELEMENT(Thu),\
    DECL_ENUM_ELEMENT(Fri),\
    DECL_ENUM_ELEMENT(Sat),\
    DECL_ENUM_ELEMENT(MAX_DAY),\

#define IMPLEMENT_ENUM( ENUM_NAME ) \
    static char* gs_##ENUM_NAME [] = { \
    WEEK_DAY_ELEMENT \
};  \
    static char* GetString##ENUM_NAME(enum tag##ENUM_NAME index){ return gs_##ENUM_NAME [index]; }

BEGIN_ENUM(WeekDay) 
{
    WEEK_DAY_ELEMENT
}
END_ENUM(WeekDay)

#undef DECL_ENUM_ELEMENT
#define DECL_ENUM_ELEMENT( Element ) #Element
    IMPLEMENT_ENUM(WeekDay)

class TestEnumToString
{
public:
    TestEnumToString()
    {
        cout<<"****** BENGIN TestEnumToString *******"<<endl;
        for (int index = (int)Sun; index < MAX_DAY; ++index)
        {
            cout<< GetStringWeekDay(WeekDay(index))<<" day is "<< index <<"th day, " <<endl;
        }
        cout<<"****** END TestEnumToString *******"<<endl;

        WeekDay day = Wen;
    }
};

#endif