#include "Scribble.h"
#include <string>
#include <iostream>

using namespace std;

void Scribble::addPoint(float x, float y, float r, float g, float b, int size){
    points.push_back(new Point(x, y, r, g, b, size));
}

void Scribble::draw(){
    for (unsigned int i = 0; i < points.size(); i++){
        points[i]->draw();
    }
}

Scribble::~Scribble(){
    for (unsigned int i = 0; i < points.size(); i++){
        delete points[i];
    }
    points.clear();
}

bool Scribble::contains(float mx, float my) {
    if (points.size() != 1) {
        float topLeftCornerX = points[0]->getX();
        float topLeftCornerY = points[0]->getY();
        float bottomRightCornerX = points[0]->getX();
        float bottomRightCornerY = points[0]->getY();
        for (unsigned int i = 1; i < points.size(); i++) {
            if (points[i]->getX() < topLeftCornerX) {
                topLeftCornerX = points[i]->getX();
            }
            if (points[i]->getY() > topLeftCornerY) {
                topLeftCornerY = points[i]->getY();
            }
            if (points[i]->getX() > bottomRightCornerX) {
                bottomRightCornerX = points[i]->getX();
            }
            if (points[i]->getY() < bottomRightCornerY) {
                bottomRightCornerY = points[i]->getY();
            }
        }
        cout << "Bounds found for Scribble.  Top left corner is (" << topLeftCornerX << ", " << topLeftCornerY << ") and bottom right corner is (" << bottomRightCornerX << ", " << bottomRightCornerY << ")" << endl;
        cout << "Clicked at mx: " << mx << ", my: " << my << endl;
        if (mx >= topLeftCornerX - 0.05 && mx <= bottomRightCornerX + 0.05 && my <= topLeftCornerY + 0.05 && my >= bottomRightCornerY - 0.05) {
            return true;
        }
        return false;
    }
    else {
        if (mx >= points[0]->getX() - 0.05 && mx <= points[0]->getX() + 0.05 && my <= points[0]->getY() + 0.05 && my >= points[0]->getY() - 0.05) {
            return true;
        }
        return false; 
    }
}

void Scribble::setColor(float r, float g, float b) {
    for (unsigned int i = 0; i < points.size(); i++) {
        points[i]->setColor(r, g, b);
    }
    return;
}

void Scribble::setPosition(float mx, float my, float originalMX, float originalMY) {
    float changeInX = mx - originalMX;
    float changeInY = my - originalMY;
    for (unsigned int i = 0; i < points.size(); i++) {
        points[i]->setPosition(changeInX, changeInY, 0, 0);
    }
}

string Scribble::getSelectedShape() {
    return "Scribble";
}

void Scribble::changeSize(float changeNum) {
    if ((points[1]->getSize() - 2 < 3) && (changeNum < 0)) {
        cout << "Scribble is at minimum size" << endl;
        return;
    }
    else {
        float accommodatedSizeChangeSpecificallyForPoints;
        if (changeNum > 0) {
            accommodatedSizeChangeSpecificallyForPoints = 2;
        }
        if (changeNum < 0) {
            accommodatedSizeChangeSpecificallyForPoints = -2;
        }
        for (unsigned int i = 0; i < points.size(); i++) {
            points[i]->changeSize(accommodatedSizeChangeSpecificallyForPoints);
        }
        draw();
        return;
    }
}