//
// Created by kostas on 30/1/21.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
#include <vector>
typedef std::vector<std::pair<int, int>> SNAKE;
class Snake {
public:
    Snake(int x, int y);
    SNAKE& GetSnake();
    void DrawSnake(void(*DrawHandler)(int,int,char));
private:
    SNAKE snake_;
    int snake_size;
};


#endif //SNAKE_SNAKE_H
