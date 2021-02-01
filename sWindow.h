//
// Created by kostas on 30/1/21.
//

#ifndef SWINDOW_H
#define SWINDOW_H
#include <vector>
#include <ncurses.h>

typedef std::vector<std::pair<int, int>> SNAKE;
class sWindow {
public:
    sWindow(int x_pos, int y_pos);
    ~sWindow() {
        endwin();
    }
    void DrawChar(int x, int y, char c);
    void DrawSnake(char c);
    void MoveHorizontal(bool right);
    void MoveVertical(bool down);
private:
    int width_, height_;
    WINDOW* window_;
    int snake_size_;
    SNAKE snake_;
};


#endif //SWINDOW_H
