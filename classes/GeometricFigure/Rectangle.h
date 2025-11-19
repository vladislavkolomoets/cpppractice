#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "GeometricFigure.h"

class Rectangle : public GeometricFigure
{
private:
    double a{}, b{}; 
    
public: 
    Rectangle() = delete;

    Rectangle(double _a, double _b) : a(_a), b(_b)
    {}

    double calculateArea() override;
    
    double calculatePerimeter() override;
};

#endif // RECTANGLE_H