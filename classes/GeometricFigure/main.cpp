#include <iostream>
#include <cmath>
#include <cassert>

#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

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