
#ifndef SHAPE_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

class Shape
{
    public:
        Shape(int sides, double length, double width, string color);
        ~Shape();
        int getSides() const;
        string getType() const;
        string getColor() const;
        double getLength() const;
        double getWidth() const;
        void setLength(double length);
        void setWidth(double width);
        virtual double getArea() const;
        virtual double getPerimeter() const;
        bool operator==(Shape& shape);
        bool operator!=(Shape& shape);
        friend ostream& operator<<(ostream& os, Shape& shape);
        virtual void print(ostream& os) const;
    protected:
        string type;
        string color;
        int sides;
        double length;
        double width;

};

class Circle : public Shape
{
    public:
        Circle(double radius, string color);
        void setRadius(double radius);
        double getArea() const override;
        double getPerimeter() const override;
        virtual void print(ostream& os) const override;

    private:
        double radius;
        double area;
};

class Rectangle : public Shape
{
    public:
        Rectangle(double length, double width, string color);
        double getArea() const override;
        double getPerimeter() const override;

        void print(ostream& os) const override;
};

class Square : public Shape
{
    public:
        Square(double length, string color);
        double getArea() const override;
        double getPerimeter() const override;

        void print(ostream& os) const override;
};

class RightTriangle : public Shape
{
    public:
        RightTriangle(double base, double height, string color);
        double getArea() const override;
        double getPerimeter() const override;
        void setBase(double base);
        void setHeight(double height);
        void print(ostream& os) const override;
    private:
        double base;
        double height;
};

#endif