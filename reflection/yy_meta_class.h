/************************************************************************/
/* 
@author:    junliang
@brief:     a class of a class.
@time:      2018-1-8
*/
/************************************************************************/
#pragma once

#include <map>
#include <string>
#include "yy_var.h"



struct MetaField;
struct MetaMethod;



struct MetaClass
{
    typedef void* (*CB_Create)();
    typedef void(*CB_Destroy)(void* ptr);

    CB_Create m_createCallBack;
    CB_Destroy m_destroyCallBack;
    std::string m_name;
    std::string m_parent;
    std::map<std::string, MetaMethod*> m_methods;
    std::map<std::string, MetaField*> m_fields;
};

