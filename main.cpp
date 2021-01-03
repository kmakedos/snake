#include <iostream>
#include "Snake.h"
#include "Grid.h"
using namespace std;
int main(int argc, char *argv[]) {
    Grid grid = Grid(20,4);
    std::cout << grid;
    std::list<std::pair<int, int>> x;
    x.push_back(std::pair<int,int>(2,3));

    grid.AddLine(x);
}
