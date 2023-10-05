//Main file to test shapes.

#include "Shape.h"

int main() 
{
    //Create a vector of shapes.
    vector<Shape*> shapes;

    //Create a circle.
    Circle* circle = new Circle(5, "red");
    shapes.push_back(circle);

    //Create a rectangle.
    Rectangle* rectangle = new Rectangle(5, 10, "blue");
    shapes.push_back(rectangle);

    //Create a square.
    Square* square = new Square(5.5, "green");
    shapes.push_back(square);

    //Create a triangle.
    RightTriangle* triangle = new RightTriangle(5, 10, "yellow");
    shapes.push_back(triangle);


    //Print out the shapes.
    for (int i = 0; i < shapes.size(); i++)
    {
        cout << *shapes[i] << endl;
    }

    //Compare the shapes.
    cout << "Circle == Rectangle: " << (*circle == *rectangle) << endl;
    cout << "Circle != Rectangle: " << (*circle != *rectangle) << endl;
    cout << "Circle == Circle: " << (*circle == *circle) << endl;
    cout << "Circle != Circle: " << (*circle != *circle) << endl;

    //Modify the shapes.
    cout << "Modifying circle radius to 10..." << endl;
    circle->setRadius(10);

    cout << "\nModifying rectangle length to 10..." << endl;
    rectangle->setLength(10);

    cout << "\nModifying square length to 10..." << endl;
    square->setLength(10);

    cout << "\nModifying triangle base to 10...\n\n" << endl;
    triangle->setBase(10);

    //Print out the shapes.
    for (int i = 0; i < shapes.size(); i++)
    {
        cout << *shapes[i] << endl;
    }


    //Delete the shapes to protect from memory leaks.
    for (int i = 0; i < shapes.size(); i++)
    {
        delete shapes[i];
    }




    return 0;
}