#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"
#include <string>

using namespace std;

class Polygon : public Shape{
    float x;
    float y;
    int sides;
    float length;
    float r;
    float g;
    float b;

public:
    Polygon();
    Polygon(float x, float y, int sides, float length, float r, float g, float b);

    void draw();
    bool contains(float mx, float my);
    void setColor(float r, float g, float b);
    friend struct AppTest;

    string getSelectedShape();
};

#endif