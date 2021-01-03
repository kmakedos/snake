//
// Created by kostas on 24/12/20.
//

#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <list>
#include <ostream>
class Snake{
public:
    Snake(int x1, int y1);
private:
    std::list<std::pair<int, int>> points_;
};

#endif 
