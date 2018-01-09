#include "test.h"

Test::Test()
{
    m_pos.x = 1.0f;
    m_pos.y = 2.0f;
}

float Test::SetPosition(Point* pos)
{
    m_pos = *pos;
    return m_pos.x;
}