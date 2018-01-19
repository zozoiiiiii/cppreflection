/************************************************************************/
/* 
@author:    junliang
@brief:     test
@time:      8/31/2016
*/
/************************************************************************/
#pragma once

#include "../reflection/yy_reflection.h"

struct Point
{
    YY_BEGIN(Point, "");
    YY_FIELD(&Point::x, "x", "");
    YY_END;

    ///////
    float x;
    float y;
};

YY_TYPEHELPER(Point, YVT_CLASS);

class Test
{
    YY_BEGIN(Test, "");
    YY_FIELD(&Test::m_pos, "position", "");
    YY_METHOD(&Test::SetPosition, "Set", "");
    YY_END;
public:
    Test();
    float SetPosition(Point* pos);
private: 
    Point m_pos;
};
