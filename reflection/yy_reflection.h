/************************************************************************/
/* 
@author:    junliang
@brief:     cpp reflection

meta class is used in 
ORM(python : Object Relational Mapping)
ue4 blueprint
qt

@sample:
@time:      2018-1-8
*/
/************************************************************************/
#pragma once

#include "yy_meta_class.h"
#include "yy_meta_field.h"
#include "yy_meta_method.h"
#include "yy_meta_method_void.h"
#include <string>

#define YY_BEGIN(cls, parent_)                                     \
private:                                                           \
    static void* Create_##cls() { return new cls(); }              \
    static void Destroy_##cls(void* p) { delete ((cls*)p); }       \
public:                                                            \
    static MetaClass* MetaClassInstance()                          \
    {                                                              \
        static MetaClass s_MetaClass;                              \
		s_MetaClass.m_name = #cls;                                 \
		s_MetaClass.m_parent = parent_;                            \
        s_MetaClass.m_createCallBack = &Create_##cls;              \
        s_MetaClass.m_destroyCallBack = &Destroy_##cls;            \
        MetaField* pField = NULL; \
        MetaMethod* pMethod = NULL;

#define YY_END  return &s_MetaClass; }

#define YY_VIRTUAL_BEGIN(cls, parent_)                             \
public:                                                            \
    static MetaClass* MetaClassInstance()                          \
    {                                                              \
        static MetaClass s_MetaClass;                              \
        s_MetaClass.m_name = #cls;                                 \
        s_MetaClass.m_parent = parent_;                            \
        MetaField* pField = NULL;                                  \
        MetaMethod* pMethod = NULL;


#define YY_FIELD(field_, name_, extension_)                        \
    pField = MakeField(field_);                                    \
    pField->m_strExtension = extension_;                           \
	pField->m_strName = name_;                                     \
    s_MetaClass.m_fields[pField->m_strName] = pField;

#define YY_METHOD(method_, name_, extension_)                      \
    pMethod = MakeMethod(method_);                                 \
    pMethod->m_strName = name_;                                    \
    pMethod->m_strExtension = extension_;                          \
    s_MetaClass.m_methods[pMethod->m_strName] = pMethod;
