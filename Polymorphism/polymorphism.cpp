/// Polymorphism.cpp
/// Copyright (c) 2014 Julian-Miller under The MIT License (MIT)
/// This file demonstrates some of the basic ways polymorphism can be used
/// in C++.
#include <iostream>


/// A simple Shape interface which provides a method to get the Shape's area
class Shape {
public:
    virtual float getArea() const = 0;
};


/// A Rectangle is a Shape with a specific width and height
class Rectangle : public Shape {
private:
    float width;
    float height;

public:
    Rectangle(float width, float height) : width(width), height(height) { }
    virtual float getArea() const { return width * height; }
};


/// A Circle is a Shape with a specific radius
class Circle : public Shape {
private:
    float radius;

public:
    Circle(float radius) : radius(radius) { }
    virtual float getArea() const { return 3.14159f * radius * radius; }
};


/// Prints the area of a Shape to standard output.
/// Note that polymorphism only works with pointer and reference types:
/// 'void printArea(const Shape* shape) { ... }' would also be valid, but
/// 'void printArea(Shape shape) { ... }' would not.
void printArea(const Shape& shape) {
    std::cout << "Area: " << shape.getArea() << std::endl;
}


/// Main function to experiment with our Shapes
int main() {

    // Instantiate Rectangle 2 units wide and 6 units high
    Rectangle r(2, 6);

    // Remember, polymorphism only works with pointer and reference types, so
    // declare a Shape pointer, and tell it to point to the Rectangle. This
    // variable has a static type of Shape, and a dynamic type of Rectangle.
    // 'Shape& shape = r' would also be valid, but
    // 'Shape shape = r' would not.
    Shape* shape = &r;

    std::cout << r.getArea() << std::endl;      // Calls Rectangle.printArea()
    std::cout << shape->getArea() << std::endl; // Calls shape's dynamic-type's
                                                // printArea()

    // Instantiate Circle with radius of 5 units
    Circle c(5);

    // Tell Shape pointer to point to the Circle; The variable
    // 'shape' always has a static type of Shape, but its dynamic
    // type is now Circle
    shape = &c;

    printArea(r);       // Print Rectangle's area
    printArea(c);       // Print Circle's area
    printArea(*shape);  // Print shape's dynamic-type (Circle)'s area

    return 0;
}