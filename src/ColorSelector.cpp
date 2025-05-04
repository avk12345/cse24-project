#include "ColorSelector.h"
#include "Enums.h"
#include <FL/Enumerations.H>
#include <bobcat_ui/bobcat_ui.h>

using namespace bobcat;

void ColorSelector::deselectAllColors() {
    if(!red->empty() && !green->empty() && !blue->empty()) {
        customButton->label("");
    }
    redButton->label("");
    orangeButton->label("");
    yellowButton->label("");
    greenButton->label("");
    blueButton->label("");
    indigoButton->label("");
    violetButton->label("");
}

void ColorSelector::visualizeSelectedColor() {
    if (color == RED) {
        redButton->label("@+5square");
    }
    else if (color == ORANGE) {
        orangeButton->label("@+5square");
    }
    else if (color == YELLOW) {
        yellowButton->label("@+5square");
    }
    else if (color == GREEN) {
        greenButton->label("@+5square");
    }
    else if (color == BLUE) {
        blueButton->label("@+5square");
    }
    else if (color == INDIGO) {
        indigoButton->label("@+5square");
    }
    else if (color == VIOLET) {
        violetButton->label("@+5square");
    }
    else if (color == CUSTOM) {
        if((!red->empty() && !green->empty() && !blue->empty()) && ((red->value() >= 0 && red->value() <= 255) && 
        (green->value() >= 0 && green->value() <= 255) && (blue->value() >= 0 && blue->value() <= 255)))  {
            customButton->label("@+5square");
            customButton->color(fl_rgb_color(red->value(), green->value(), blue->value()));
        }
        else {
            redButton->label("@+5square");
        }
    }
}

void ColorSelector::onClick(bobcat::Widget* sender) {
    deselectAllColors();

    if (sender == redButton) {
        color = RED;
    }
    else if (sender == orangeButton) {
        color = ORANGE;
    }
    else if (sender == yellowButton) {
        color = YELLOW;
    }
    else if (sender == greenButton) {
        color = GREEN;
    }
    else if (sender == blueButton) {
        color = BLUE;
    }
    else if (sender == indigoButton) {
        color = INDIGO;
    }
    else if (sender == violetButton) {
        color = VIOLET;
    }
    else if (sender == customButton) {
        if (!red->empty() && !green->empty() && !blue->empty() &&
        red->value()   >= 0 && red->value()   <= 255 &&
        green->value() >= 0 && green->value() <= 255 &&
        blue->value()  >= 0 && blue->value()  <= 255) {
            color = CUSTOM;
        }
        else if (color == CUSTOM) {
            color = RED;
            showMessage("Invalid RGB values were provided, defaulting to the color red.");
        }
    }

    if (onChangeCb) {
        onChangeCb(this);
    }

    visualizeSelectedColor();
    redraw();
}

void ColorSelector::onCustomColorInputChange(bobcat::Widget* sender) {
    if ((!red->empty() && !green->empty() && !blue->empty())) {
        if ((red->value() >= 0 && red->value() <= 255) && 
        (green->value() >= 0 && green->value() <= 255) && (blue->value() >= 0 && blue->value() <= 255)) {
            customButton->color(fl_rgb_color(red->value(), green->value(), blue->value()));
        }
        else {
            customButton->color(FL_BACKGROUND_COLOR);
            customButton->label("");
        }
    } else {
        customButton->color(FL_BACKGROUND_COLOR);
    }
    customButton->redraw();
}

Color ColorSelector::getColor() const {
    if (color == RED) {
        return Color(255/255.0, 0/255.0, 0/255.0);
    }
    else if (color == ORANGE) {
        return Color(255/255.0, 127/255.0, 0/255.0);
    }
    else if (color == YELLOW) {
        return Color(255/255.0, 255/255.0, 0/255.0);
    }
    else if (color == GREEN) {
        return Color(0/255.0, 255/255.0, 0/255.0);
    }
    else if (color == BLUE) {
        return Color(0/255.0, 0/255.0, 255/255.0);
    }
    else if (color == INDIGO) {
        return Color(75/255.0, 0/255.0, 130/255.0);
    }
    else if (color == VIOLET) {
        return Color(148/255.0, 0/255.0, 211/255.0);
    }
    else if (color == CUSTOM) {
        if((!red->empty() && !green->empty() && !blue->empty()) && ((red->value() >= 0 && red->value() <= 255) && 
        (green->value() >= 0 && green->value() <= 255) && (blue->value() >= 0 && blue->value() <= 255)))  {
            return Color(red->value() / 255.0, green->value() / 255.0, blue->value() / 255.0);
        }
        else {
            return Color(255/255.0, 0/255.0, 0/255.0);
        }
    }
    else {
        return Color();
    }
}

ColorSelector::ColorSelector(int x, int y, int w, int h) : Group(x, y, w, h) {
    redButton = new Button(x, y, 50, 50, "");
    orangeButton = new Button(x + 50, y, 50, 50, "");
    yellowButton = new Button(x + 100, y, 50, 50, "");
    greenButton = new Button(x + 150, y, 50, 50, "");
    blueButton = new Button(x + 200, y, 50, 50, "");
    indigoButton = new Button(x + 250, y, 50, 50, "");
    violetButton = new Button(x + 300, y, 50, 50, "");
    customButton = new Button(x + 500, y, 50, 50, "");

    color = RED;

    redButton->color(fl_rgb_color(255, 0, 0));
    redButton->labelcolor(FL_WHITE);
    orangeButton->color(fl_rgb_color(255, 127, 0));
    orangeButton->labelcolor(FL_WHITE);
    yellowButton->color(fl_rgb_color(255, 255, 0));
    yellowButton->labelcolor(FL_WHITE);
    greenButton->color(fl_rgb_color(0, 255, 0));
    greenButton->labelcolor(FL_WHITE);
    blueButton->color(fl_rgb_color(0, 0, 255));
    blueButton->labelcolor(FL_WHITE);
    indigoButton->color(fl_rgb_color(75, 0, 130));
    indigoButton->labelcolor(FL_WHITE);
    violetButton->color(fl_rgb_color(148, 0, 211));
    violetButton->labelcolor(FL_WHITE);
    customButton->labelcolor(FL_WHITE);

    visualizeSelectedColor();

    ON_CLICK(redButton, ColorSelector::onClick);
    ON_CLICK(orangeButton, ColorSelector::onClick);
    ON_CLICK(yellowButton, ColorSelector::onClick);
    ON_CLICK(greenButton, ColorSelector::onClick);
    ON_CLICK(blueButton, ColorSelector::onClick);
    ON_CLICK(indigoButton, ColorSelector::onClick);
    ON_CLICK(violetButton, ColorSelector::onClick);
    ON_CLICK(customButton, ColorSelector::onClick);

    red = new IntInput(x + 350, y, 50, 50, "");
    green = new IntInput(x + 400, y, 50, 50, "");
    blue = new IntInput(x + 450, y, 50, 50, "");

    ON_CHANGE(red, ColorSelector::onCustomColorInputChange);
    ON_CHANGE(green, ColorSelector::onCustomColorInputChange);
    ON_CHANGE(blue, ColorSelector::onCustomColorInputChange);
}