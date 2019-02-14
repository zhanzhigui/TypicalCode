#include <stdint.h>
#include <string>

#include "enumeration.h"

namespace tn { 
    
    std::map<std::string, ValueEnumTable>*                 Enumeration::type_value_enums = nullptr;
    std::map<std::string, NameEnumTable>*                  Enumeration::type_name_enums = nullptr;
    
    Enumeration::Enumeration() : value_(0), name_("undefined")
    {
    
    }
    
    Enumeration::Enumeration(int16_t value, const std::string& name, const std::string& type_name) : value_(value), name_(name)
    {
        value_ = value;
        name_ = name;
        
        static std::map<std::string, ValueEnumTable>      _type_value_enums;
        static std::map<std::string, NameEnumTable>       _type_name_enums;
        if (type_value_enums == nullptr)
        {
            type_value_enums = &_type_value_enums;
            type_name_enums = &_type_name_enums;
        }
        
        std::map<std::string, ValueEnumTable>::iterator type_value_enums_iter = type_value_enums->find(type_name);
        
        if(type_value_enums_iter != type_value_enums->end())
        {
            ValueEnumTable& value_enum = type_value_enums_iter->second;
            value_enum.emplace(value, this);
        }
        else
        {
            ValueEnumTable value_enum;
            value_enum.emplace(value, this);
            type_value_enums->emplace(type_name, value_enum);
        }
        
        std::map<std::string, NameEnumTable>::iterator type_name_enums_iter = type_name_enums->find(type_name);
        
        if(type_name_enums_iter != type_name_enums->end())
        {
            NameEnumTable& name_enums = type_name_enums_iter->second;
            name_enums.emplace(name, this);
        }
        else
        {
            NameEnumTable name_enums;
            name_enums.emplace(name, this);
            type_name_enums->emplace(type_name, name_enums);
        }
    }
    
}
