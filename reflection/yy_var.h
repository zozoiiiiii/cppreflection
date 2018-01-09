/************************************************************************/
/* 
@author:    junliang
@brief:     variant helper
@time:      2017-12-19
*/
/************************************************************************/
#pragma once
#include <string>
#include <wchar.h>


typedef signed __int8                      sint8;         //char
typedef unsigned __int8                    uint8;
typedef signed __int16                     sint16;        //short
typedef unsigned __int16                   uint16;
typedef signed __int32                     sint32;        //int
typedef unsigned __int32                   uint32;
typedef signed __int64                     sint64;
typedef unsigned __int64                   uint64;

// variant type
enum VarType
{
    YVT_UNKNOWN,
    YVT_BOOL,
    YVT_SINT32,
    YVT_SINT64,
    YVT_FLOAT,
    YVT_DOUBLE,
    YVT_STRING,
    YVT_WSTRING,
    YVTYPE_CLASS,
};

// variant flag
enum VarFlag
{
    YVF_UNKNOWN,
    YVF_NORMAL,             // variant
    YVF_POINTER,            // variant*
    YVF_CONST_POINTER,      // const variant*
    YVF_REF,                // variant&
    YVF_CONST_REF,          // const variant&
};

template<typename T>
struct VarHelper
{
    static int GetType(){return YVT_UNKNOWN;}
    static std::string GetTypeName(){return "";}
    static VarFlag GetFlag(){return YVF_NORMAL;}

    // out parameter
    static bool IsOut(){return false;} 
    static T Get(void* data){return *(T*)data;}
};

template<typename T> 
struct VarHelper<T*>{ 
    static int GetType(){return YVT_UNKNOWN;}
    static std::string GetTypeName(){return "";}
    static VarFlag GetFlag(){return YVF_POINTER;} 
    static bool IsOut(){return true;} 
    static T* Get(void* data){return *(T**)data;} 
};



template<typename T>
struct VarHelper<const T*>{ 
    static int GetType(){return YVT_UNKNOWN;}
    static std::string GetTypeName(){return "";}
    static VarFlag GetFlag(){return YVF_CONST_POINTER;} 
    static bool IsOut(){return false;} 
    static const T* Get(void* data){return *(const T**)data;} 
}; 

template<typename T>
struct VarHelper<T&>{ 
    static int GetType(){return YVT_UNKNOWN;}
    static std::string GetTypeName(){return "";}
    static VarFlag GetFlag(){return YVF_REF;} 
    static bool IsOut(){return true;} 
    static T& Get(void* data){return *(T*)data;} 
}; 

template<typename T>
struct VarHelper<const T&>{ 
    static int GetType(){return YVT_UNKNOWN;}
    static std::string GetTypeName(){return "";}
    static VarFlag GetFlag(){return YVF_CONST_REF;} 
    static bool IsOut(){return false;} 
    static const T& Get(void* data){return *(T*)data;} 
}; 



#define YY_TYPEHELPER(T, type_) \
    template<> \
struct VarHelper<T>{ \
    static int GetType(){return type_;} \
    static std::string GetTypeName(){return #T;} \
        static VarFlag GetFlag(){return YVF_NORMAL;} \
        static bool IsOut(){return false;} \
        static T Get(void* data){return *(T*)data;} \
    }; \
     template<> \
struct VarHelper<T*>{ \
    static int GetType(){return type_;} \
    static std::string GetTypeName(){return #T;} \
        static VarFlag GetFlag(){return YVF_POINTER;} \
        static bool IsOut(){return true;} \
        static T* Get(void* data){return *(T**)data;} \
     }; \
     template<> \
struct VarHelper<const T*>{ \
    static int GetType(){return type_;} \
    static std::string GetTypeName(){return #T;} \
        static VarFlag GetFlag(){return YVF_CONST_POINTER;} \
        static bool IsOut(){return false;} \
        static const T* Get(void* data){return *(const T**)data;} \
     }; \
     template<> \
struct VarHelper<T&>{ \
    static int GetType(){return type_;} \
    static std::string GetTypeName(){return #T;} \
        static VarFlag GetFlag(){return YVF_REF;} \
        static bool IsOut(){return true;} \
        static T& Get(void* data){return *(T*)data;} \
     }; \
     template<> \
struct VarHelper<const T&>{ \
    static int GetType(){return type_;} \
    static std::string GetTypeName(){return #T;} \
        static VarFlag GetFlag(){return YVF_CONST_REF;} \
        static bool IsOut(){return false;} \
        static const T& Get(void* data){return *(T*)data;} \
     }; 



using namespace std;

//fundamental type
YY_TYPEHELPER(bool, YVT_BOOL);
YY_TYPEHELPER(int, YVT_SINT32);
YY_TYPEHELPER(sint64, YVT_SINT64);
YY_TYPEHELPER(float, YVT_FLOAT);
YY_TYPEHELPER(double, YVT_DOUBLE);
YY_TYPEHELPER(string, YVT_STRING);
YY_TYPEHELPER(wstring, YVT_WSTRING);


