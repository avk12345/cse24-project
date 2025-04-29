#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <string>

using namespace std;

class Triangle : public Shape{
    float base;
    float height;

public:
    Triangle();
    Triangle(float x, float y, float base, float height, float r, float g, float b);
    void draw();
    bool contains(float mx, float my);
    friend struct AppTest;
    string getSelectedShape();
    void setColor(float r, float g, float b);
};

#endif