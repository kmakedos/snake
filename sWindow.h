//
// Created by kostas on 30/1/21.
//

#ifndef SWINDOW_H
#define SWINDOW_H
#include <ncurses.h>

class sWindow {
public:
    sWindow();
    ~sWindow() {
        endwin();
    }
    WINDOW* GetHandler();
    void DrawChar(int x, int y, char c);
private:
    int width_, height_;
    WINDOW* window_;
};


#endif //SWINDOW_H
