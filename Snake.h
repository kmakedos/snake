//
// Created by kostas on 30/1/21.
//

#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <ncurses.h>
enum DIRECTION{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};

typedef std::vector<std::pair<int, int>> SNAKE;
class Snake {
public:
    Snake(int x_pos, int y_pos);
    ~Snake() {
        endwin();
    }
    void DrawChar(int x, int y, char c);
    void DrawSnake(char c);
    void MoveHorizontal(int step);
    void MoveVertical(int step);
    void Move(DIRECTION direction);
    WINDOW* GetWindow(){
        return window_;
    }
private:
    int width_, height_;
    WINDOW* window_;
    int snake_size_;
    SNAKE snake_;
    DIRECTION direction_;
};


#endif //SNAKE_H
