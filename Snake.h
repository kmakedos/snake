//
// Created by kostas on 24/12/20.
//

#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <list>

class Snake{
public:
    Snake(int grid_X, int grid_Y, int snake_size);
    void ShowGrid();
    void PutSnake(char c);
    int CalcPos(int x, int y);
    void Move(int x, int y);
private:
    int x_size_;
    int y_size_;
    std::list<std::pair<int,int>> snake_;
    std::vector<char> grid_;
    int snake_size_;
};

#endif 
