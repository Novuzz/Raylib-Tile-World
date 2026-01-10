#include "numberf.hpp"

//I used sign with bit shift operation just
//to test, perharps it's better just use if statements
float sign(float x)
{
    if (x == 0)
        return 0;
    long *number = (long *)(&x);
    long num = (*number);
    num = num & 0x80000000 | 0x3f800000;
    return *(float *)(&num);
}
float min(float a, float b)
{
    if (a < b)
        return a;
    return b;
}
float max(float a, float b)
{
    if (a > b)
        return a;
    return b;
}
