#include <iostream>
#include "Snake.h"
using namespace std;
int main(int argc, char *argv[]) {
    Snake snake = Snake(4,3, 3);
    std::cout << snake;
}
