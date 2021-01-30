//
// Created by kostas on 30/1/21.
//

#include "sWindow.h"
sWindow::sWindow() {
    cbreak();
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    refresh();
    width_ = (COLS * 0.8);
    height_ = (LINES * 0.8);
    window_ = newwin(height_, width_, (LINES - height_)/2, (COLS-width_)/2);
    box(window_, '0', '0');
    wborder(window_,'|', '|', '-', '-', '+', '+','+','+');
    wrefresh(window_);
}

WINDOW* sWindow::GetHandler() {
    return window_;
}

void sWindow::DrawChar(int x, int y, char c) {
    if ((x < width_) && (x>0) && (y>0) && (y<height_)) {
        mvwaddch(window_, y, x, c);
        wrefresh(window_);
    }
    else{
        addstr("Print outside wall\n");
    }
}