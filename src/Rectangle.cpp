#include "Rectangle.h"
#include <GL/freeglut.h>

Rectangle::Rectangle() : Shape() {
    width = 0.4;
    height = 0.4;
}

Rectangle::Rectangle(float x, float y, float width, float height, float r, float g, float b) : Shape(x, y) {
    this->width = width;
    this->height = height;
    setColor(r, g, b);
}

void Rectangle::draw() {
    glColor3f(r, g, b);

    glBegin(GL_POLYGON);
        glVertex2f(x - width/2, y + height/2);
        glVertex2f(x + width/2, y + height/2);
        glVertex2f(x + width/2, y - height/2);
        glVertex2f(x - width/2, y - height/2);
    glEnd();
}

bool Rectangle::contains(float mx, float my) {
    if (mx >= x - width/2 && mx <= x + width/2 && my <= y + height/2 && my >= y - height/2) {
        return true;
    }
    return false;
}
