#include <iostream>

using namespace std;
void greet(string name="User") {
    std::cout << "Hello " << name << std::endl;
}

// C doesn’t allow functions with same name. C++ does.
int add(int a, int b=10) {
    return a+b;
}

int add(int a, int b, int c) { // overloaded
    return a+b+c;
}

int main(int argc, char *argv[]) {
    greet();
    greet("Raya");
    std::cout << add(1, 2) << std::endl;
    std::cout << add(1, 2, 3) << std::endl; 
    return 0;
}