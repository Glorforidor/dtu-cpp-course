#include "shapes.h"
#include <math.h>

Shape::Shape(double x) : Shape(x, x) {}

Shape::Shape(double height, double width)
{
    h = height;
    w = width;
}

Shape::~Shape() {}

double Shape::width()
{
    return w;
}

double Shape::height()
{
    return h;
}

double Shape::area()
{
    return w * h;
}

void Shape::setWidth(double width)
{
    w = width;
}

void Shape::setHeight(double height)
{
    h = height;
}

Rectangle::Rectangle(double height, double width) : Shape(height, width) {}

Rectangle::~Rectangle(){};

double Rectangle::perimeter()
{
    return 2 * (width() + height());
}

void Rectangle::rotate()
{
    auto h = height();
    auto w = width();
    setHeight(w);
    setWidth(h);
}

Square::Square(double length) : Shape(length) {}

Square::~Square() {}

double Square::perimeter()
{
    return 4 * width();
}

void Square::rotate() {}

Circle::Circle(double radius) : Shape(radius * 2)
{
    r = radius;
}

Circle::~Circle() {}

double Circle::area()
{
    return M_PI * (r * r);
}

double Circle::perimeter()
{
    return 2 * M_PI * r;
}

void Circle::rotate() {}