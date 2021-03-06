#pragma once
#include "Border.h"
#include "Rect.h"
#include <string>

struct Window {
    Rect rect = {};
    string title = "";
    Border border = {};
    int z = 0;
    Screen screen = {};
    bool visible = true;

    Window(Rect rect, string title = "", Border border = Border{BorderStyle::Plain}, int z = 0) {
        this->title = title;
        this->rect = rect;
        this->border = border;
        this->z = z;
        resizeScreen();
    };

    void resizeScreen() {
        this->screen = Screen(rect.width - 2, rect.height - 2);
    }

    // Flatten window contents and decoration together into one Screen
    Screen render() {
        Screen output_screen = Screen(rect.width, rect.height);

        // Draw border corners
        output_screen.draw(Point(0, 0), border.get(BorderElement::TopLeft));
        output_screen.draw(Point(rect.width - 1, 0), border.get(BorderElement::TopRight));
        output_screen.draw(Point(0, rect.height - 1), border.get(BorderElement::BottomLeft));
        output_screen.draw(Point(rect.width - 1, rect.height - 1), border.get(BorderElement::BottomRight));

        // Draw top and bottom edges
        for (int i = 1; i < rect.width - 1; i++) {
            output_screen.draw(Point(i, 0), border.get(BorderElement::Horizontal));
            output_screen.draw(Point(i, rect.height - 1), border.get(BorderElement::Horizontal));
        };
        // Draw left and right edges
        for (int i = 1; i < rect.height - 1; i++) {
            output_screen.draw(Point(0, i), border.get(BorderElement::Vertical));
            output_screen.draw(Point(rect.width - 1, i), border.get(BorderElement::Vertical));
        };

        output_screen.draw(Point(1, 1), screen);
        return output_screen;
    }
};