#include "Circle.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cmath>
#include <iostream>

using namespace std;

Circle::Circle() : Shape() {
    radius = 0.2;
}

Circle::Circle(float x, float y, float radius, float r, float g, float b) : Shape(x, y) {
    this->radius = radius;
    setColor(r, g, b);
}

void Circle::draw() {
    glColor3f(r, g, b);

    float inc = M_PI / 32;
    glBegin(GL_POLYGON);
        for (float theta = 0; theta <= 2 * M_PI; theta += inc){
            glVertex2d(x + cos(theta) * radius, y + sin(theta) * radius);
        }
    glEnd();
}

bool Circle::contains(float mx, float my) {
    if(mx >= x - radius && my >= y - radius && mx <= x + radius && my <= y + radius) {
        return true;
    }

    return false;
}

void Circle::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

string Circle::getSelectedShape() {
    return "Circle";
}

void Circle::changeSize(float changeNum) {
    radius += changeNum;
    draw();
}