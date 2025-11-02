#include <iostream>
#include <cmath>
#include <cassert>

class GeometricFigure
{
public:
    virtual double calculateArea() = 0;
    
    virtual double calculatePerimeter() = 0;
};

class Triangle : public GeometricFigure
{
private:
    double a{}, b{}, c{}; 
    
public: 
    Triangle() = delete;

    Triangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c)
    {}

    double calculateArea() override
    {
        double s = 0.5 * calculatePerimeter();
        
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    
    double calculatePerimeter() override
    {
        return a + b + c;
    }
};

class Rectangle : public GeometricFigure
{
private:
    double a{}, b{}; 
    
public: 
    Rectangle() = delete;

    Rectangle(double _a, double _b) : a(_a), b(_b)
    {}
    
    double calculateArea() override
    {
        return a * b;
    }
    
    double calculatePerimeter() override
    {
        return 2 * (a + b);
    }
};

class Circle : public GeometricFigure
{
private:
    double r{}; 
    
public: 
    Circle() = delete;

    Circle(double _r) : r(_r)
    {}

    double calculateArea() override
    {
        return M_PI * r * r;
    }
    
    double calculatePerimeter() override
    {
        return 2 * M_PI * r;
    }
};

int main()
{
    Triangle triangle(3.0, 4.0, 5.0);
    assert(triangle.calculatePerimeter() == 12.0);
    assert(std::abs(triangle.calculateArea() - 6.0) < 1e-6);

    Rectangle rectangle(2.0, 3.0);
    assert(rectangle.calculateArea() == 6.0);
    assert(rectangle.calculatePerimeter() == 10.0);

    Circle circle(1.0);
    double expectedArea = M_PI * 1.0 * 1.0;
    double expectedCircumference = 2 * M_PI * 1.0;
    assert(std::abs(circle.calculateArea() - expectedArea) < 1e-6);
    assert(std::abs(circle.calculatePerimeter() - expectedCircumference) < 1e-6);

    std::cout << "All done!" << std::endl;

    return 0;
}