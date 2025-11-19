#include "Circle.h"

double Circle::calculateArea() 
{
    return M_PI * r * r;
}

double Circle::calculatePerimeter() 
{
    return 2 * M_PI * r;
}