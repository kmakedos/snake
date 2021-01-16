//
// Created by kostas on 24/12/20.
//
#include <iomanip>
#include "Snake.h"

Snake::Snake(int length, int x0, int y0, int x_size, int y_size) {
    length_ = length;
    x0_ = x0;
    y0_ = y0;
    x_size_ = x_size;
    y_size_ = y_size;
    Fill('0');
}

void Snake::Move(int steps, int direction) {

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

std::ostream& operator<<(std::ostream& out, Snake& grid){
    int x = 0;
    for (auto const &it: grid.grid_content_){
        if (x++ % grid.x_size_ == 0){
            out << std::endl;
        }
        out << std::setw(2) << it;
    }
    return out;
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

