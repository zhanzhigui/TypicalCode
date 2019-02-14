//
//  enumeration.h      
//
//  Copyright (c) 2018 Telenav, Inc. All rights reserved.
//  This program is UNPUBLISHED PROPRIETARY property of Telenav.
//  Only for internal distribution
//
//

#ifndef _TN_ENUMERATION_H_
#define _TN_ENUMERATION_H_

#include <stdint.h>
#include <string>
#include <map>
#include <typeinfo>
#include <stddef.h>
#include <iostream>
#include <vector>

using namespace std;

namespace tn { 
    
    typedef signed short int16_t;
    struct Enumeration;
    
    typedef std::map<std::string, const Enumeration*>       NameEnumTable;
    typedef std::map<int16_t, const Enumeration*>           ValueEnumTable;
    
    struct Enumeration
    {
        Enumeration();
        
        Enumeration(int16_t value, const std::string& name, const std::string& type_name);
        
        virtual ~Enumeration() { }
        
        int16_t value() const { return value_; } 

        std::string name() const { return name_; } 

        bool operator == (const Enumeration& other) const { return (this->value_ == other.value_); }
        
        template<typename T> static T AsEnumeration(int value)
        {
            const std::string& type_name = typeid(T).name();
            
            std::map<std::string, ValueEnumTable>::iterator type_value_enums_iter = type_value_enums->find(type_name);
            
            if(type_value_enums_iter != type_value_enums->end())
            {
                const ValueEnumTable& value_enums = type_value_enums_iter->second;
                ValueEnumTable::const_iterator value_enums_iter = value_enums.find(value);
                
                if(value_enums_iter != value_enums.end())
                {
                    const Enumeration& enum_object = *(value_enums_iter->second);
                    return dynamic_cast<const T&>(enum_object);
                }
            }
            
            T undefined;
            return undefined;
        }
        
        template<typename T> static T AsEnumeration(const std::string& name)
        {
            const std::string& type_name = typeid(T).name();
            
            std::map<std::string, NameEnumTable>::iterator type_name_enums_iter = type_name_enums->find(type_name);
            
            if(type_name_enums_iter != type_name_enums->end())
            {
                const NameEnumTable& name_enums = type_name_enums_iter->second;
                NameEnumTable::const_iterator name_enums_iter = name_enums.find(name);
                
                if(name_enums_iter != name_enums.end())
                {
                    const Enumeration& enum_object = *(name_enums_iter->second);
                    return dynamic_cast<const T&>(enum_object);
                }
            }
            
            T undefined;
            return undefined;
        }

        /*template<typename T> 
        static std::vector<const T*> Enumerations()
        {
            std::vector<const T*> enumerations;

            const std::string& type_name = typeid(T).name();
            
            std::map<std::string, ValueEnumTable>::iterator type_value_enums_iter = type_value_enums->find(type_name);
            
            if(type_value_enums_iter != type_value_enums->end())
            {
                const ValueEnumTable& value_enums = type_value_enums_iter->second;

                for (ValueEnumTable::const_iterator value_enums_iter = value_enums.begin();
                    value_enums_iter != value_enums.end(); ++value_enums_iter)
                {
                    enumerations.push_back(dynamic_cast<T*>(value_enums_iter->second));
                }
            }
            
            return enumerations;
        }*/

    private:

        int16_t         value_;

        std::string     name_;
        
        static std::map<std::string, ValueEnumTable>*                  type_value_enums;
        static std::map<std::string, NameEnumTable>*                   type_name_enums;
        
    };
    
    
#define NAV_ENUM_(EnumType) \
    struct EnumType : tn::Enumeration \
    { \
        EnumType() { } \
        EnumType(int value, const std::string& name) : \
        Enumeration(value, name, typeid(EnumType).name()) { } \
    }; 

#define ENUM_ITEM_(EnumType, ConstName, Value, Name) \
    const EnumType ConstName(Value, Name);

#define END_ENUM_ ;

} 


NAV_ENUM_(TEST)
    ENUM_ITEM_(TEST, AC_TOLL_BOOTH,                1, "toll-booth");
    ENUM_ITEM_(TEST, AC_SERVICE_AREA,              2, "service-area");
    ENUM_ITEM_(TEST, AC_HIGHWAY_EXIT,              3, "highway-exit");
END_ENUM_

class TestEnumeration
{
public:
    TestEnumeration()
    {
        cout<<"****** BENGIN TestEnumToString *******"<<endl;

        string str("toll-booth");
        const TEST& t = TEST::AsEnumeration<TEST>(str);
        TEST t2;
        t2 = t;
        const tn::Enumeration& e = TEST::AsEnumeration<TEST>(2);
        cout << e.name() << " " <<e.value() <<endl;
        cout << t.name() << " " <<t.value() <<endl;
        /*//std::vector<const TEST*> vec = TEST::Enumerations<TEST>();
        for (size_t index = 0; index < vec.size(); ++index)
        {
            
        }*/
        
        cout<<"****** END TestEnumToString *******"<<endl;
    }
};

#endif 