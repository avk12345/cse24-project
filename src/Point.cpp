#include "Point.h"
#include <GL/freeglut.h>
#include <string>

using namespace std;

Point::Point() {
    size = 7;
}

Point::Point(float x, float y) : Shape(x, y) {
    size = 7;
}

Point::Point(float x, float y, float r, float g, float b) : Shape(x, y) {
    setColor(r,g,b);
    size = 7;
}

Point::Point(float x, float y, float r, float g, float b, int size) : Shape(x, y) {
    setColor(r,g,b);
    this->size = size;
}

void Point::draw() {
    glColor3f(r, g, b);
    glPointSize(size);

    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
}

float Point::getX() const {
    return x;
}

float Point::getY() const {
    return y;
}

float Point::getR() const {
    return r;
}

float Point::getG() const {
    return g;
}

float Point::getB() const {
    return b;
}

int Point::getSize() const {
    return size;
}

bool Point::contains(float mx, float my) {
    return false;
}

string Point::getSelectedShape() {
    return "Point";
}

void Point::changeSize(float changeNum) {
    size += changeNum;
    draw();
}