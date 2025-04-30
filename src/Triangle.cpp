#include "Triangle.h"
#include <GL/freeglut.h>

Triangle::Triangle() : Shape() {
    base = 0.2;
    height = 0.2;
}

Triangle::Triangle(float x, float y, float base, float height, float r, float g, float b) : Shape(x, y) {
    this->base = base;
    this->height = height;
    setColor(r, g, b);
}

void Triangle::draw() {
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
        glVertex2f(x - base/2, y - height/2);
        glVertex2f(x, y + height/2);
        glVertex2f(x + base/2, y - height/2);
    glEnd();
}

bool Triangle::contains(float mx, float my) {
    if(mx >= x - base/2 && my >= y - height/2 && mx <= x + base/2 && my <= y + height/2) {
        return true;
    }

    return false;
}

void Triangle::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

string Triangle::getSelectedShape() {
    return "Triangle";
}

void Triangle::changeSize(float changeNum) {
    base += changeNum;
    height += changeNum;
    draw();
}