#ifndef GEOMETRICFIGURE_H
#define GEOMETRICFIGURE_H

class GeometricFigure
{
public:
    virtual double calculateArea() = 0;
    
    virtual double calculatePerimeter() = 0;
};

#endif // GEOMETRICFIGURE_H