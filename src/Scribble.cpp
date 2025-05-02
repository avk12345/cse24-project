#include "Scribble.h"
#include <string>

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
    for (unsigned int i = 0; i < points.size(); i++) {
        if (points[i]->contains(mx, mx)) {
            return true;
        }
    }
    return false;
}

void Scribble::setColor(float r, float g, float b) {
    for (unsigned int i = 0; i < points.size(); i++) {
        points[i]->setColor(r, g, b);
    }
    return;
}

string Scribble::getSelectedShape() {
    return "Scribble";
}

void Scribble::changeSize(float changeNum) {
    return;
}