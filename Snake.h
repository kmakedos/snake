//
// Created by kostas on 24/12/20.
//

#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <list>
/*#include <vector>
#include <list>
#include <ostream>
class Snake{
public:
    Snake(int x_size, int y_size);
    void AddSnake(int length, int x0, int y0);
    void Move(int steps, int direction);
    void Fill(char c);
    void FillPoint(int x, int y, char c);
    void AddLine(std::list<std::pair<int, int>> &list);
    void DeleteLine(std::list<std::pair<int, int>> &list);
private:
    std::list<std::pair<int, int>> points_;
    int length_;
    int x0_, y0_;
    int x_size_;
    int y_size_;
    std::vector<char> grid_content_;
};*/

class Snake{
public:
    Snake(int x_size, int y_size, int snake_length);
    void UpdateGrid();
    friend std::ostream &operator<<(std::ostream &os, Snake &snake);
private:
    std::vector<int> grid_;
    std::list<std::pair<int, int>> snake_;
    int x_size_, y_size_, snake_length_;
};

#endif 
