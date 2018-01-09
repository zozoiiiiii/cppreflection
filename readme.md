
# how to use:

struct Point
{
    YY_BEGIN(Point, "");
    YY_FIELD(&Point::x, "x", "");
    YY_END;

    ///////
    float x;
    float y;
};


# help url:
http://garret.ru/cppreflection/docs/reflect.html