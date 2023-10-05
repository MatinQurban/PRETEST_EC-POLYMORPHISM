#include "Shape.h"


Shape::Shape(int sides, double length, double width, string color)
{
    this->sides = sides;
    this->length = length;
    this->width = width;
    this->color = color;

    if (sides == 1 || sides == 0)
    {
        type = "Circle";
    }
    else if (sides == 4 && length == width)
    {
        type = "Square";
    }
    else if (sides == 4 && length != width)
    {
        type = "Rectangle";
    }
    else if (sides == 3)
    {
        type = "Triangle";
    }
    else
    {
        type = "Polygon";
    }
}

Shape::~Shape()
{
    delete this;
}

int Shape::getSides() const
{
    return sides;
}

string Shape::getType() const
{
    return type;
}

string Shape::getColor() const
{
    return color;
}

double Shape::getLength() const
{
    return length;
}

double Shape::getWidth() const
{
    return width;
}

void Shape::setLength(double length)
{
    this->length = length;
}

void Shape::setWidth(double width)
{
    this->width = width;
}

double Shape::getArea() const
{
    return length * width;
}

double Shape::getPerimeter() const
{
    return 0;
}

bool Shape::operator==(Shape& shape)
{
    return (this->getArea() == shape.getArea() && this->getSides() == shape.getSides() && this->getWidth() == shape.getWidth() && this->getLength() == shape.getLength());
}

bool Shape::operator!=(Shape& shape)
{
    return (this->getArea() != shape.getArea() || this->getSides() != shape.getSides() || this->getWidth() != shape.getWidth() || this->getLength() != shape.getLength());
}

ostream& operator<<(ostream& os, Shape& shape)
{
    shape.print(os);  
    return os;
}

void Shape::print(ostream& os) const
{
    os << left << setw(20) << "Shape" << setw(20) << "Sides" << setw(20) << "Length" << setw(20) << "Width" << setw(20) << "Area" << setw(20) << "Color" << endl;
    os << setw(20) << getType() << setw(20) << getSides() << setw(20) << getLength() << setw(20) << getWidth() << setw(20) << getArea() << setw(20) << getColor();
    os << endl;
}


//==================================================

Circle::Circle(double radius, string color) : Shape(0, radius, M_PI, color)
{
    this->radius = radius;
}

void Circle::setRadius(double radius)
{
    this->radius = radius;
    length = radius;
}

double Circle::getArea() const
{
    return M_PI * radius * radius;
}

double Circle::getPerimeter() const
{
    return 2 * M_PI * radius;
}

void Circle::print(ostream& os) const 
{
    os << left << setw(20) << "Shape" << setw(20) << "Sides" << setw(20) << "Radius" << setw(20) << "Area" << setw(20) << "Circumfrence" << setw(20) << "Color" << endl;
    os << setw(20) << getType() << setw(20) << getSides() << setw(20) << getLength() << setw(20) << getArea() << setw(20) << getPerimeter() << setw(20) << getColor();
    os << endl;
}

ostream& operator<<(ostream& os, Circle& circle)
{
    circle.print(os);
    return os;
}

//==================================================

Rectangle::Rectangle(double length, double width, string color) : Shape(4, length, width, color)
{
    this->length = length;
    this->width = width;
}

double Rectangle::getArea() const
{
    return length * width;
}

double Rectangle::getPerimeter() const
{
    return 2 * length + 2 * width;
}

ostream& operator<<(ostream& os, Rectangle& rectangle)
{
    rectangle.print(os);
    return os;
}

void Rectangle::print(ostream& os) const
{
    os << left << setw(20) << "Shape" << setw(20) << "Sides" << setw(20) << "Length" << setw(20) << "Width" << setw(20) << "Area" << setw(20) << "Perimeter" << setw(20) << "Color" << endl;
    os << setw(20) << getType() << setw(20) << getSides() << setw(20) << getLength() << setw(20) << getWidth() << setw(20) << getArea() << setw(20) << getPerimeter() << setw(20) << getColor();
    os << endl;
}


//==================================================

Square::Square(double length, string color) : Shape(4, length, length, color)
{
    this->length = length;
    width = length;
}

double Square::getArea() const
{
    return length * length;
}

double Square::getPerimeter() const
{
    return 4 * length;
}

ostream& operator<<(ostream& os, Square& square)
{
    square.print(os);
    return os;
}

void Square::print(ostream& os) const
{
    os << left << setw(20) << "Shape" << setw(20) << "Sides" << setw(20) << "Length" << setw(20) << "Area" << setw(20) << "Perimeter" << setw(20) << "Color" << endl;
    os << setw(20) << getType() << setw(20) << getSides() << setw(20) << getLength() << setw(20) << getArea() << setw(20) << getPerimeter() << setw(20) << getColor();
    os << endl;
}


//==================================================

RightTriangle::RightTriangle(double base, double height, string color) : Shape(3, base, height, color)
{
    this->base = base;
    this->height = height;
    length = base;
    width = height;
}

double RightTriangle::getArea() const
{
    return 0.5 * base * height;
}

double RightTriangle::getPerimeter() const
{
    return base + height + sqrt(base * base + height * height);
}

void RightTriangle::setBase(double base)
{
    this->base = base;
    length = base;
}

void RightTriangle::setHeight(double height)
{
    this->height = height;
    width = height;
}

ostream& operator<<(ostream& os, RightTriangle& rightTriangle)
{
    rightTriangle.print(os);
    return os;
}

void RightTriangle::print(ostream& os) const
{
    os << left << setw(20) << "Shape" << setw(20) << "Sides" << setw(20) << "Base" << setw(20) << "Height" << setw(20) << "Area" << setw(20) << "Perimeter" << setw(20) << "Color" << endl;
    os << setw(20) << getType() << setw(20) << getSides() << setw(20) << getLength() << setw(20) << getWidth() << setw(20) << getArea() << setw(20) << getPerimeter() << setw(20) << getColor();
    os << endl;
}

