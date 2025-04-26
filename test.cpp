#include <iostream>

using namespace std;

namespace Nokia {
    void cout() {
        std::cout << "Nokia Connecting People ..." << std::endl;
    }
};

class Dog {
public:
    string breed;

public:
    Dog() {breed = "Indie";}
    //  Member Initializer Lists
    Dog(string s) :breed(s) {}; 
    // above syntax It’s more efficient and idiomatic C++, especially when initializing complex objects.

    ~Dog() {
        std::cout << "Dog of breed [" << breed <<"] is destroyed." << std::endl;
    }

};

int main(int argc, char *argv[]) {
    Dog d1;
    Dog d2("Husky");

    std::cout << d1.breed << std::endl << d2.breed << std::endl;
    return 0;
}