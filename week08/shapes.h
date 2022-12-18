#pragma once

class Shape
{
public:
    Shape(double x);
    Shape(double height, double width);
    virtual ~Shape();
    virtual double area();
    virtual double perimeter() = 0;
    virtual void rotate() = 0;
    virtual double width();
    virtual double height();

protected:
    virtual void setWidth(double width);
    virtual void setHeight(double height);

private:
    double w;
    double h;
};

class Rectangle : virtual public Shape
{
public:
    Rectangle(double height, double width);
    ~Rectangle();
    virtual double perimeter();
    virtual void rotate();
};

class Square : virtual public Shape
{
public:
    Square(double length);
    ~Square();
    virtual double perimeter();
    virtual void rotate();
};

class Circle : public Shape
{
public:
    Circle(double radius);
    ~Circle();
    virtual double area();
    virtual double perimeter();
    virtual void rotate();

private:
    double r;
};