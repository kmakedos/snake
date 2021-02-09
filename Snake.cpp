//
// Created by kostas on 30/1/21.
//
#include <stdlib.h>
#include <unistd.h>
#include "Snake.h"
Snake::Snake(int x_pos, int y_pos) {
    snake_size_ = 10;
    for (int i = 0; i < snake_size_; i++){
        snake_.emplace_back(x_pos-i,y_pos);
    }

    width_ = (COLS * 0.8);
    height_ = (LINES * 0.8);
    window_ = newwin(height_, width_, (LINES - height_)/2, (COLS-width_)/2);
    keypad(window_, TRUE);
    box(window_, '0', '0');
    wborder(window_,'|', '|', '-', '-', '+', '+','+','+');
    wrefresh(window_);
    direction_ = RIGHT;
}


void Snake::DrawChar(int x, int y, char c) {
    if ((x < width_) && (x>0) && (y>0) && (y<height_)) {
        mvwaddch(window_, y, x, c);
        wrefresh(window_);
    }
    else{
        nodelay(window_, FALSE);
        addstr("Game Over! \n");
        wrefresh(window_);
        sleep(2);
        exit(EXIT_SUCCESS);
    }
}


void Snake::DrawSnake(char c) {
    for (auto &it: snake_){
        DrawChar(it.first, it.second, c);
    }
}



void Snake::MoveHorizontal(int step) {
    DrawSnake(' ');
    int new_x = snake_.cbegin()->first + step;
    snake_.emplace(snake_.cbegin(), new_x, snake_.cbegin()->second);
    snake_.pop_back();
    DrawSnake('@');
}
void Snake::MoveVertical(int step) {
    DrawSnake(' ');
    int new_y = snake_.cbegin()->second + step;
    snake_.emplace(snake_.cbegin(), snake_.cbegin()->first, new_y);
    snake_.pop_back();
    DrawSnake('@');
}

void Snake::Move(DIRECTION direction) {
    int step;
    if (direction == NONE){
        direction = direction_;
    }
    else {
        direction_ = direction;
    }
    switch (direction){
        case LEFT:
            step = -1;
            MoveHorizontal(step);
            break;
        case RIGHT:
            step = 1;
            MoveHorizontal(step);
            break;
        case UP:
            step = -1;
            MoveVertical(step);
            break;
        case DOWN:
            step = 1;
            MoveVertical(step);
            break;
        default:
            break;
    }
}