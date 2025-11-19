#include "Rectangle.h"

double Rectangle::calculateArea() 
{
    double s = 0.5 * calculatePerimeter();
        
    return a * b;
}

double Rectangle::calculatePerimeter() 
{
    return 2 * (a + b);
}