#include <iostream>
#include "Snake.h"
using namespace std;
int main(int argc, char *argv[]) {
    Snake snake = Snake(11,7, 3);
    snake.ShowGrid();
    snake.Move(2,2);
    snake.ShowGrid();
}
