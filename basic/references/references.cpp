#include <iostream>
#include <stdio.h>

using namespace std;

// References are like aliases — you can’t “null” or “reassign” them.

void increment(int &x) {
    x++;
}

int main(int argc, char *argv[]) {
    int x = 10;
    increment(x);
    std::cout << x << std::endl;
    return 0;
}