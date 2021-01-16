#include <iostream>
#include "Snake.h"
using namespace std;
int main(int argc, char *argv[]) {
    int X= 10; int Y=4;
    Snake snake = Snake(3, 0, 0, X,Y);
    std::cout << snake;
    std::list<std::pair<int, int>> x;
    for (int i =0; i < X; i++){
        for (int j=0; j < Y; j++){
            x.emplace_back(i,2);
        }
    }
    snake.AddLine(x);
    std::cout << "\n";
    std::cout << snake;
}
