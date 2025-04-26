#include <iostream>

using namespace std;

/*
🔹 1. struct vs class

    In C++, both struct and class support methods, constructors, and inheritance.

    Only difference:
    → struct defaults to public,
    → class defaults to private.
*/

struct Person {
    string name;
    void sayHello() {
        cout << "Hi, I'm " << name << endl;
    }
};


class Animal {
    string species;

public:
    Animal(string s) {
        this->species = s;  // this pointer: like self in Python — points to current object
    }

    ~Animal() {
        std::cout << "I am Destroctor" << std::endl;
    }

    void print() {
        cout << "Species: " << species << endl;
    }

};

int main(int argc, char *argv[]) {
    Person p;
    Animal c("Cat");

    p.name = "Dora";
    p.sayHello();

    c.print();

    return 0;
}