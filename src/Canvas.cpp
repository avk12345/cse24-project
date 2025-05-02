#include "Canvas.h"
#include "Circle.h"
#include "Enums.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Scribble.h"
#include "Toolbar.h"
#include "Triangle.h"
#include <GL/freeglut.h>
#include <cstdlib>

using namespace std;

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
  curr = nullptr;
}

void Canvas::addPoint(float x, float y, float r, float g, float b, int size) {
  shapes.push_back(new Point(x, y, r, g, b, size));
}

void Canvas::addCircle(float x, float y, float radius, float r, float g,
                       float b) {
  shapes.push_back(new Circle(x, y, radius, r, g, b));
}

void Canvas::addTriangle(float x, float y, float base, float height, float r,
                         float g, float b) {
  shapes.push_back(new Triangle(x, y, base, height, r, g, b));
}

void Canvas::addRectangle(float x, float y, float width, float height, float r,
                          float g, float b) {
  shapes.push_back(new Rectangle(x, y, width, height, r, g, b));
}

void Canvas::addPolygon(float x, float y, int sides, float length, float r,
                        float g, float b) {
  shapes.push_back(new Polygon(x, y, sides, length, r, g, b));
}

void Canvas::clear() {
  for (unsigned int i = 0; i < shapes.size(); i++) {
    delete shapes[i];
  }
  shapes.clear();
}

void Canvas::undo() {
  if (shapes.size() > 0) {
    delete shapes[shapes.size() - 1];
    shapes.pop_back();
  }
}

void Canvas::render() {
  for (unsigned int i = 0; i < shapes.size(); i++) {
    shapes[i]->draw();
  }

  if (curr) {
    curr->draw();
  }
}

void Canvas::startScribble() { curr = new Scribble(); }

void Canvas::updateScribble(float x, float y, float r, float g, float b,
                            int size) {
  if (curr) {
    curr->addPoint(x, y, r, g, b, size);
  }
}

void Canvas::endScribble() {
  if (curr) {
    shapes.push_back(curr);
    curr = nullptr;
  }
}

void Canvas::bringToFront(Shape *shape) {
  for (long unsigned int i = 0; i < shapes.size(); i++) {
    if (shapes[i] == shape) {
      Shape *curr = shape;
      shapes.erase(shapes.begin() + i);
      shapes.push_back(curr);
      break;
    }
  }
}

void Canvas::pushToBack() {
  //
}

void Canvas::moveShape() {
  //
}

void Canvas::changeSize(Shape* selectedShape, float changeNum) {
    cout << "Size being changed" << endl;

    selectedShape->changeSize(changeNum);
}

Shape *Canvas::getSelectedShape(float mx, float my) {
  Shape *selectedShape = nullptr;

  if (shapes.size() >= 1) {
    for (unsigned int i = shapes.size(); i > 0; i--) {
      if (shapes[i - 1]->contains(mx, my)) {
        cout << "Clicked on shape[" << i - 1 << "]" << endl;
        selectedShape = shapes[i - 1];
        break;
      }
    }
  }

  if (selectedShape == nullptr) {
    cout << "No selected shape" << endl;
  }

  return selectedShape;
}