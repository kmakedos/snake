//
// Created by kostas on 30/1/21.
//

#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <unordered_map>
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
    void ExtendSnake(int size);
    bool GameOver();
    WINDOW* GetWindow(){
        return window_;
    }
private:
    int width_, height_;
    WINDOW* window_;
    int food_char;
    int snake_char;
    int snake_size_;
    int snake_extend_;
    SNAKE snake_;
    DIRECTION direction_;
    std::unordered_map<int, int> food_points;
    bool game_over;
};


#endif //SNAKE_H
