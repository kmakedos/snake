//
// Created by kostas on 24/12/20.
//
#include <iostream>
#include "Snake.h"

Snake::Snake(int grid_X, int grid_Y, int snake_size) {
    x_size_ = grid_X;
    y_size_ = grid_Y;
    snake_size_ = snake_size;
    for (int i =0; i < x_size_ * y_size_; i++){
        grid_.emplace_back('0');
    }
    for (int i = 0; i < snake_size_; i++){
        snake_.emplace(snake_.cbegin(), i + x_size_/2-snake_size_,y_size_/2);

    }
}


void Snake::ShowGrid() {
    PutSnake('1');
    for (int y = 0; y < y_size_; y++){
        std::cout << "\n";
        for (int x = 0; x < x_size_; x++){
            std::cout << grid_[CalcPos(x,y)] << " ";
        }
    }
}

int Snake::CalcPos(int x, int y){
    return y * x_size_ + x;
}


void Snake::PutSnake(char c) {
    int i = 0 ;
    for (auto &it: snake_){
        grid_[CalcPos(it.first, it.second)] = c;
    }
}

void Snake::Move(int x, int y) {
    PutSnake('0');
    auto tmp = snake_.cbegin();
    snake_.emplace(snake_.cbegin(), tmp->first, tmp->second-1);
    snake_.pop_back();
}