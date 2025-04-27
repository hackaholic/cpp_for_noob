#include <iostream>

using namespace std;

/* 
A lambda is an anonymous function — no name, just a function.
👉 [] means "lambda",
👉 () means "no parameters",
👉 {} means "function body".

You just create a function on the spot and pass it around easily!

👉 STL algorithms love lambdas.
👉 Callbacks need lambdas.
*/

int main() {

    auto greet = []() {std::cout << "Hello Coco" << std::endl;};

    greet();

    return 0;
}