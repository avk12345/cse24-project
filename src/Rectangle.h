#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <string>

using namespace std;

class Rectangle : public Shape {
    float width;
    float height;

public:
    Rectangle();
    Rectangle(float x, float y, float width, float height, float r, float g, float b);
    void draw();
    bool contains(float mx, float my);
    void setColor(float r, float g, float b);
    string getSelectedShape();
};

#endif