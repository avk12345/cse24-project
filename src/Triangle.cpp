#include "Triangle.h"
#include <GL/freeglut.h>
#include <iostream>

using namespace std;

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

string Triangle::getSelectedShape() {
    return "Triangle";
}

void Triangle::changeSize(float changeNum) {
    if ((base <= 0.1 && height <= 0.1) && (changeNum < 0)) {
        cout << "Triangle is at minimum size" << endl;
        return;
    }
    base += changeNum;
    height += changeNum;
    draw();
}