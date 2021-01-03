//
// Created by kostas on 3/1/21.
//

#ifndef SNAKE_GRID_H
#define SNAKE_GRID_H
#include <vector>
#include <list>
#include <ostream>

class Grid {
public:
    Grid():x_size_(20),y_size_(4){Fill();}
    Grid(int x_size, int y_size):x_size_(x_size),y_size_(y_size){Fill();}
    void Fill();
    void AddLine(std::list<std::pair<int, int>> &list);
    friend std::ostream &operator<<(std::ostream &os, Grid &grid);
private:
    int x_size_;
    int y_size_;
    std::vector<int> grid_content_;
};


#endif //SNAKE_GRID_H
