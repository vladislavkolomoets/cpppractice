#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>

#include "GeometricFigure.h"

class Circle : public GeometricFigure
{
private:
    double r{}; 
    
public: 
    Circle() = delete;

    Circle(double _r) : r(_r)
    {}

    double calculateArea() override;
    
    double calculatePerimeter() override;
};

#endif // CIRCLE_H