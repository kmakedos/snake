//
// Created by kostas on 30/1/21.
//
#include <ncurses.h>
#include <iostream>
#include "Snake.h"

Snake::Snake(int x, int y) {
    snake_size = 3;
    for (int i = 0; i < snake_size; i++){
        snake_.emplace_back(x-i,y);
    }
}

SNAKE& Snake::GetSnake() {
    return snake_;
}

void Snake::DrawSnake(void(*DrawHandler)(int,int,char)) {
   for (auto &it: snake_){
       DrawHandler(it.first, it.second, 'C');
   }
}


