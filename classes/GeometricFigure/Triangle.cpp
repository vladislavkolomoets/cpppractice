#include "Triangle.h"

double Triangle::calculateArea()
{
    double s = 0.5 * calculatePerimeter();
        
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Triangle::calculatePerimeter()
{
    return a + b + c;
}