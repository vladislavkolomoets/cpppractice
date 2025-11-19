#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>

#include "GeometricFigure.h"

class Triangle : public GeometricFigure
{
private:
    double a{}, b{}, c{}; 
    
public: 
    Triangle() = delete;

    Triangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c)
    {}

    double calculateArea() override;
    
    double calculatePerimeter() override;
};

#endif // TRIANGLE_H