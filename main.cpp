#include <iostream>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include "Snake.h"

int kbhit(WINDOW* window){
    int ch = wgetch(window);
    if (ch != ERR){
        return ch;
    }
    else {
        return 0;
    }
}

using namespace std;
int main(int argc, char *argv[]) {
    cbreak();
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    refresh();
    Snake snake = Snake(COLS/2, LINES/2);
    nodelay(snake.GetWindow(), TRUE);
    time_t start_time, curr_time;
    struct tm counter = {0};
    double seconds = 0;
    start_time = time(NULL);
    int c = ' ';
    c = wgetch(snake.GetWindow());
    while ((c != KEY_EXIT) && (seconds < 200) && (! snake.GameOver())){
        snake.Move(NONE);
        int speed_factor = (int)(seconds/10) % 20 / 4 + 1;
        usleep(200000/speed_factor);
        if ((c = kbhit(snake.GetWindow())) != 1){
            switch (c) {
                case KEY_UP:
                    snake.Move(UP);
                    break;
                case KEY_DOWN:
                    snake.Move(DOWN);
                    break;
                case KEY_LEFT:
                    snake.Move(LEFT);
                    break;
                case KEY_RIGHT:
                    snake.Move(RIGHT);
                    break;
                default:
                    snake.Move(NONE);
                    break;
            }
        }
        curr_time = time(NULL);
        seconds = difftime(curr_time, start_time);
    }

    delwin(snake.GetWindow());
    if (snake.GameOver()){
        std::cout << "Game Over!!\n\n";
    }

}
