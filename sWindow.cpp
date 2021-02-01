//
// Created by kostas on 30/1/21.
//

#include "sWindow.h"
sWindow::sWindow(int x_pos, int y_pos) {
    snake_size_ = 3;
    for (int i = 0; i < snake_size_; i++){
        snake_.emplace_back(x_pos-i,y_pos);
    }
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


void sWindow::DrawChar(int x, int y, char c) {
    if ((x < width_) && (x>0) && (y>0) && (y<height_)) {
        mvwaddch(window_, y, x, c);
        wrefresh(window_);
    }
    else{
        addstr("Print outside wall\n");
    }
}


void sWindow::DrawSnake(char c) {
    for (auto &it: snake_){
        DrawChar(it.first, it.second, c);
    }
}

void sWindow::MoveHorizontal(bool right) {
    int step = right ? 1 : -1;
    int new_x = snake_.cbegin()->first + step;
    snake_.emplace(snake_.cbegin(), new_x, snake_.cbegin()->second);
    snake_.pop_back();
}
void sWindow::MoveVertical(bool down) {
    int step = down ? 1 : -1;
    int new_y = snake_.cbegin()->second + step;
    snake_.emplace(snake_.cbegin(), snake_.cbegin()->first, new_y);
    snake_.pop_back();
}