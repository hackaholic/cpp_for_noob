#include <iostream>
using namespace std;
namespace Myspace {
    void print() {
        std:cout << "Hello from MySpace" << std::endl;
    }
}

int main(int argc, char *argv[]) {
    Myspace::print();
    return 0;
}