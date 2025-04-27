#include <iostream>

using namespace std;

// Passing a lambda into a template = SUPER FLEXIBLE.

template <typename func>
void call(func f) {
    f();
}

int main() {
    call([](){std::cout << "Hello from template lambda" << std::endl;});
    return 0;
}