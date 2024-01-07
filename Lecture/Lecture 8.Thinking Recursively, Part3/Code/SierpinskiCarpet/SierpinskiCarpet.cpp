/*
 * File: SierpinskiCarpet.cpp
 * ---------------
 * A program that draws the Sierpinski Carpet fractal.
 */
#include <iostream>
#include <string>
#include "gwindow.h"
#include "gobjects.h"
#include "gthread.h"
using namespace std;

/* Draws a square in the window, given the coordinates
 * of the upper-left corner.
 */
void drawSquare(double x, double y,
                double sideLength);

/* Draws a Sierpinski carpet of the given order.
 * Returns how many total squares were drawn.
 */
int drawCarpet(double x, double y,
               double sideLength,
               int order) {
    /* Base Case: An order-0 carpet is just a filled
     * square.
     */
    if (order == 0) {
        drawSquare(x, y, sideLength);
        return 1;
    }
    /* Recursive Case: Draw eight smaller Sierpinski
     * carpets, arranged in a square, with the center
     * square left off.
     */
    else {
        int squares = 0;
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                /* Skip the center square. */
                if (!(row == 1 && col == 1)) {
                    double newSide = sideLength / 3;
                    double newX = x + col * newSide;
                    double newY = y + row * newSide;

                    squares += drawCarpet(newX, newY,
                                          newSide,
                                          order - 1);
                }
            }
        }
        return squares;
    }
}


/* Constants controlling the window size. */
const double kWindowWidth  = 1000;
const double kWindowHeight = 800;

/* Margin from window sides to content area. */
const double kMargin = 40;

/* Colors! */
const string kBackgroundColor = "white";
const string kRectangleColor  = "#400080";

/* Maximum order to draw. */
const double kMaxOrder = 5;

void clear();
void repaintWindow();

/* Yikes, global variables! This is normally a big
 * no-no, but we've chosen to do it here because we
 * want the lecture to focus on the recursion
 * mechanics rather than the logic of working with
 * windows.
 */
GWindow* theWindow;

/* Main program */
int main() {
    GWindow window(kWindowWidth, kWindowHeight);
    window.setExitOnClose(true);
    theWindow = &window;

    while (true) {
        for (int order = 0; order <= kMaxOrder; order++) {
            clear();
            window.setTitle("Sierpinski Carpet of Order " + to_string(order));

            /* Determine the width and height of the square to draw. */
            double width  = window.getCanvasWidth()  - 2 * kMargin;
            double height = window.getCanvasHeight() - 2 * kMargin;
            double size = min(width, height);

            /* Determine position. */
            double x = (window.getCanvasWidth()  - size) / 2.0;
            double y = (window.getCanvasHeight() - size) / 2.0;

            int numSquares = drawCarpet(x, y, size, order);
            cout << "An order-" << order << " Sierpinski carpet is made "
                 << "of " << numSquares << " square(s)." << endl;
            pause(2000);
        }
    }
}

/* This somewhat clunky-looking function is
 * designed to repaint the window immediately
 * so that if we step through this code in
 * the debugger, the window is responsive and
 * shows the squares we're drawing. This is basically
 * a hack around our libraries; you aren't
 * expected to understand how this works.
 */
void repaintWindow() {
    GThread::runOnQtGuiThread([&] {
        theWindow->repaint();
    });
}

/* Clears the graphics contents from the window. */
void clear() {
    theWindow->clearCanvasPixels();
    repaintWindow();
}

void drawSquare(double x, double y,
                double size) {
    theWindow->setColor(kRectangleColor);
    theWindow->fillRect(x, y, size, size);
    repaintWindow();
}
