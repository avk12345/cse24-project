#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include <vector>
#include "Point.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Shape.h"
#include "Scribble.h"
#include "Toolbar.h"

class Canvas : public bobcat::Canvas_ {
    std::vector<Shape*> shapes;

    Scribble* curr;

    Toolbar* tool;

public:
    Canvas(int x, int y, int w, int h);

    void addPoint(float x, float y, float r, float g, float b, int size);

    void addRectangle(float x, float y, float width, float height, float r, float g, float b);

    void addCircle(float x, float y, float radius, float r, float g, float b);

    void addTriangle(float x, float y, float base, float height, float r, float g, float b);

    void addPolygon(float x, float y, int sides, float length, float r, float g, float b);

    void clear();

    void undo();

    void startScribble();

    void updateScribble(float x, float y, float r, float g, float b, int size);

    void endScribble();

    void render();

    void bringToFront(Shape* shape);
    
    void pushToBack(Shape *shape);

    void moveShape();

    void changeSize(Shape* selectedShape);

    Shape* getSelectedShape(float mx, float my);
};

#endif