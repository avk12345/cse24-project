#include "Application.h"
#include "Enums.h"
#include <bobcat_ui/bobcat_ui.h>
#include <cstddef>
#include <sys/select.h>

using namespace bobcat;
using namespace std;

void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my) {
    tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->startScribble();
        canvas->updateScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        Shape* toErase = canvas->getSelectedShape(mx, my);
        if (toErase) {
            canvas->eraseObject(toErase);
            selectedShape = nullptr;
            canvas->redraw();
        }
        //canvas->startScribble();
        //canvas->updateScribble(mx, my, 1, 1, 1, 14);
        canvas->redraw();
    }
    else if (tool == CIRCLE) {
        canvas->addCircle(mx, my, 0.1, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == TRIANGLE) {
        canvas->addTriangle(mx, my, 0.2, 0.2, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == RECTANGLE) {
        canvas->addRectangle(mx, my, 0.2, 0.2, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == POLYGON) {
        canvas->addPolygon(mx, my, 6, 0.1, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == MOUSE) {
        selectedShape = canvas->getSelectedShape(mx, my);
    }
}

void Application::onCanvasMouseUp(bobcat::Widget* sender, float mx, float my) {
    canvas->endScribble();
}

void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->updateScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    /*else if (tool == ERASER) {
        canvas->updateScribble(mx, my, 1.0, 1.0, 1.0, 14);
        canvas->redraw();
    }
    */
    else if (tool == MOUSE) {
        if (selectedShape != nullptr) {
            selectedShape->setPosition(mx, my);
            canvas->redraw();
        }
    }
}

void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar->getAction();
    TOOL tool = toolbar->getTool();
    if (tool != MOUSE) {
        selectedShape = nullptr;
    }
    if (action == CLEAR) {
        canvas->clear();
        canvas->redraw();
    }
    if (action == UNDO) {
        canvas->undo();
        canvas->redraw();
    } if ((action == PUSHFRONT) && selectedShape) {
        canvas->bringToFront(selectedShape);
        canvas->redraw();
    }
    if ((action == PUSHBACK) && selectedShape) {
        canvas->pushToBack(selectedShape);
        canvas->redraw();
    }
    if((action == DECREASE || action == INCREASE) && selectedShape) {
        cout << "size changed" << endl;
        float changeNum;
        if(action == DECREASE) {
            changeNum = -0.05;
        } else if(action == INCREASE) {
            changeNum = 0.05;
        }
        cout << changeNum << endl;
        canvas->changeSize(selectedShape, changeNum);
        canvas->redraw();
    }
    
}

void Application::onColorSelectorChange(bobcat::Widget* sender) {
    Color color = colorSelector->getColor();
    if (selectedShape && tool == MOUSE) {
        cout << "Update selected shape color" << endl;
        selectedShape->setColor(color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
}

Application::Application() {
    window = new Window(25, 75, 600, 650, "Paint Application Shapes");

    selectedShape = nullptr;

    toolbar = new Toolbar(0, 0, 50, 650);
    canvas = new Canvas(50, 0, 600, 600);
    colorSelector = new ColorSelector(50, 600, 550, 50);

    window->add(toolbar);
    window->add(canvas);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_CHANGE(toolbar, Application::onToolbarChange);
    ON_MOUSE_UP(canvas, Application::onCanvasMouseUp);
    ON_CHANGE(colorSelector, Application::onColorSelectorChange);
    window->show();
}
