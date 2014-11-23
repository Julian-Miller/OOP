/// Destructors.cpp
/// Copyright (c) 2014 Julian-Miller under The MIT License (MIT)
/// This file demonstrates the purposes of destructors, when they
/// are called, and why they are important.
#include <iostream>


/// A custom container that holds some number of integers
class Array {
private:
    
    /// The number of elements in our array
    const int size;

    /// A pointer for the dynamically allocated elements array
    int* elements;

public:
    /// The constructor dynamically allocates memory, so we need to delete
    /// this in the destructor.
    Array(int size) : size(size), elements(new int[size]) {
        std::cout << "Constructed Array of size " << size << std::endl;
    }

    int getSize() const { return size; }

    /// Operator overloading allows us to access our Array just like a built-in
    /// array, with the array subscript [] operator
    int& operator[](int i) { return elements[i]; }

    /// The destructor is called automatically when an Array instance is
    /// destroyed. We do not need to call ~Array() ourselves.
    /// We use it here to clean up the dynamically allocated elements array.
    /// Make sure your destructors are virtual when they are a part of a
    /// polymorphic base class!
    virtual ~Array() {
        delete[] elements;
        std::cout << "Array destroyed" << std::endl;
    }
};


/// An example subclass of Array, with no added functionality
class SpecialArray : public Array {
public:
    SpecialArray(int size) : Array(size) {
        std::cout << "SpecialArray constructor called" << std::endl;
    }

    ~SpecialArray() {
        std::cout << "SpecialArray destructor called" << std::endl;
    }
};


/// Demonstrate function scope of variables; our array is destroyed
/// automatically when this function is finished
void createAndDestroyArray() {

    Array myArray(10);   // Constructed Array of size 10

} // Array destroyed


/// Main function to experiment with destructors
int main() {
    std::cout << "MAIN STARTED" << std::endl;

    // Constructed Array of size 5
    // SpecialArray constructor called
    Array* arr = new SpecialArray(5);

    for (int i = 0; i < arr->getSize(); i++) {
        (*arr)[i] = i * i;
    }

    for (int i = 0; i < arr->getSize(); i++) {
        std::cout << (*arr)[i] << std::endl;
    }

    // SpecialArray destructor called
    // Array destroyed
    delete arr;
    // --------------------------------------------------------------------- //


    // Always true
    if (true) {
        Array myArray(15);  // Constructed Array of size 15

        // Do something with myArray...

    } // myArray destroyed
    // --------------------------------------------------------------------- //


    // Curly braces control the lifetime of an object
    // A variable is only available between the curly braces
    // in which it is declared
    {
        Array myArray(10); // Constructed Array of size 10
    } // myArray destroyed
    // --------------------------------------------------------------------- //


    SpecialArray specialArray(0);
    if (specialArray.getSize() > 0) {
        std::cout << "specialArray size: " << specialArray.getSize()
                  << std::endl;
    }
    else {
        std::cout << "specialArray is empty" << std::endl;
    }

    std::cout << "MAIN ENDED" << std::endl;
    return 0;

} // SpecialArray destructor called; Array Destroyed