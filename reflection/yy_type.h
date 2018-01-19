/************************************************************************/
/* 
@author:    junliang
@brief:     type
@time:      2018-1-19
*/
/************************************************************************/
#pragma once

typedef signed __int8                      sint8;         //char
typedef unsigned __int8                    uint8;
typedef signed __int16                     sint16;        //short
typedef unsigned __int16                   uint16;
typedef signed __int32                     sint32;        //int
typedef unsigned __int32                   uint32;
typedef signed __int64                     sint64;
typedef unsigned __int64                   uint64;

// variant type
enum YVarType
{
    YVT_UNKNOWN,
    YVT_BOOL,
    YVT_SINT32,
    YVT_SINT64,
    YVT_FLOAT,
    YVT_DOUBLE,
    YVT_STRING,
    YVT_WSTRING,
    YVT_CLASS,
};