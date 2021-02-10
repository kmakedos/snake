//
// Created by kostas on 30/1/21.
//
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "Snake.h"
Snake::Snake(int x_pos, int y_pos) {
    snake_size_ = 10;
    food_char = '#';
    snake_char = '@';
    snake_extend_ = 0;
    game_over = false;
    for (int i = 0; i < snake_size_; i++){
        snake_.emplace_back(x_pos-i,y_pos);
    }

    width_ = (COLS * 0.8);
    height_ = (LINES * 0.8);
    int x, y;
    for (int i = 0; i < COLS * LINES / 100; i++){
        x = rand() % (width_ - 10) + 5;
        y = rand() % (height_ - 10) + 5;
        food_points[x] = y;
    }
    window_ = newwin(height_, width_, (LINES - height_)/2, (COLS-width_)/2);
    keypad(window_, TRUE);
    box(window_, '0', '0');
    wborder(window_,'|', '|', '-', '-', '+', '+','+','+');
    wrefresh(window_);
    direction_ = RIGHT;
    for (auto &it: food_points){
        DrawChar(it.first, it.second, food_char);
    }
}


void Snake::DrawChar(int x, int y, char c) {
    if ((x < width_) && (x>0) && (y>0) && (y<height_)) {
        if ((food_points[x] == y) && (c == snake_char)){
            snake_extend_ = 1;
            food_points.erase(x);
        }
        mvwaddch(window_, y, x, c);
        wrefresh(window_);
    }
    else{
        addstr("Game Over! \n");
        game_over = true;
    }
}


void Snake::DrawSnake(char c) {
    for (auto &it: snake_){
        DrawChar(it.first, it.second, c);
    }
}

bool Snake::GameOver(){
    return game_over;
}


void Snake::MoveHorizontal(int step) {
    DrawSnake(' ');
    int new_x = snake_.cbegin()->first + step;
    int new_y = snake_.cbegin()->second;
    for (int i = 0; i < snake_extend_; i++) {
        snake_.emplace(snake_.cbegin(), new_x, new_y);
    }
    snake_.emplace(snake_.cbegin(), new_x, new_y);
    snake_.pop_back();
    snake_extend_ = 0;
    DrawSnake(snake_char);
}
void Snake::MoveVertical(int step) {
    DrawSnake(' ');
    int new_x = snake_.cbegin()->first;
    int new_y = snake_.cbegin()->second + step;
    for (int i = 0; i < snake_extend_; i++) {
        snake_.emplace(snake_.cbegin(), new_x, new_y);
    }
    snake_.emplace(snake_.cbegin(), new_x, new_y);
    snake_.pop_back();
    snake_extend_ = 0;
    DrawSnake(snake_char);
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