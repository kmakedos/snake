//
// Created by kostas on 24/12/20.
//
#include <iomanip>
#include "Snake.h"

Snake::Snake(int x_size, int y_size, int snake_length) {
    x_size_ = x_size;
    y_size_ = y_size;
    snake_length_ = snake_length;
    UpdateGrid();
}



void Snake::UpdateGrid(){
    for (int i =0; i<(x_size_ * y_size_); i++){
       grid_.emplace_back(0);
    }
}
std::ostream& operator<<(std::ostream& out, Snake& snake){
    int x = 0;
    for (auto const &it: snake.grid_){
        if (x++ % snake.x_size_ == 0){
            out << std::endl;
        }
        out << std::setw(2) << it;
    }
    return out;
}

/*
Snake::Snake(int x_size, int y_size) {
    x_size_ = x_size;
    y_size_ = y_size;
    x0_ = 0;
    y0_ = 0;
    Fill('0');
}

void Snake::AddSnake(int length, int x0, int y0 ){
    length_ = length;
    x0_ = x0;
    y0_ = y0;
    std::list<std::pair<int,int>> temp_line;
    if ((x0 - length) >= 0 ){
        for (int i = x0-length; i<x0; i++){
            temp_line.emplace_back(i, y0);
        }
    }
    AddLine(temp_line);
}

void Snake::Move(int steps, int direction) {
    if (direction == 1) {
        ;
    }
}
void Snake::Fill(char c){
    int grid_size = x_size_ * y_size_;
    for (int i = 0; i < grid_size; i++){
        grid_content_.push_back(c);
    }
}


void Snake::FillPoint(int x, int y, char c) {
    grid_content_[y * x_size_ + x] = c;
}


void Snake::AddLine(std::list<std::pair<int, int>> &list) {
    for (auto it: list){
        FillPoint(it.first, it.second, '1');
    }
}

void Snake::DeleteLine(std::list<std::pair<int, int>> &list){
    for (auto it: list){
        FillPoint(it.first, it.second, '0');
    }
}
*/
