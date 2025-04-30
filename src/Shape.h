#ifndef SHAPE_H
#define SHAPE_H

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <string>

using namespace std;

// Abstract Data Type
class Shape{
protected:
    float x, y, r, g, b;

public:
    Shape() : x(0.0), y(0.0), r(0.0), g(0.0), b(0.0) {}

    Shape(float x, float y)
        : x(x), y(y) {}

    // This function is now pure virtual
    virtual void draw() = 0;

    virtual bool contains(float mx, float my) = 0;

    virtual void setColor(float r, float g, float b) {
        this->r = r;
        this->g = g;
        this->b = b; 
    }

    virtual string getSelectedShape() = 0;

    virtual void changeSize(float changeNum) = 0;

    // Since Shape contains at least one pure virtual function
    // Shape is an Abstract Data Type

    // This forces every child of Shape to have a draw
    // function implemented

    // Any ADT must have a virtual destructor
    virtual ~Shape(){}
};

#endif