//
// Created by kostas on 3/1/21.
//
#include <iomanip>
#include <iostream>
#include "Grid.h"
void Grid::Fill(){
   int grid_size = x_size_ * y_size_;
   for (int i = 0; i < grid_size; i++){
       grid_content_.push_back(0);
   }
}


std::ostream& operator<<(std::ostream& out, Grid& grid){
    int x = 0;
    for (auto const &it: grid.grid_content_){
        if (x++ % grid.x_size_ == 0){
            out << std::endl;
        }
        out << std::setw(2) << it;
    }
    return out;
}

void Grid::AddLine(std::list<std::pair<int, int>> &list) {
    for (auto const &it: list) {
        std::cout << it.first << " " << it.second << std::endl;
    }
}