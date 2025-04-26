#include <iostream>

/*
🔥 One-Line DEATH PUNCH for Virtuals 🔥
Virtual = "Can override if you want."
Pure Virtual (=0) = "You must override, or you die (compiler error)."


❌ Cannot create object of abstract class.

✅ Can create pointer or reference of abstract class type.

✅ Must override pure virtual function in child class, otherwise child also becomes abstract.

✅ Abstract class can have normal (non-virtual) functions too.

*/

using namespace std;

class Animal {
public:
    virtual void speak() = 0;  //  Pure virtual: no body, = 0
};

class Cat: public Animal {
public:
    void speak() override {   // Must override
        std::cout << "Meow Meow!!" << std::endl;
    }
};

int main(int argc, char *argv[]) {
    // Animal a;  // ERROR! Can't create object of abstract class

    Cat c;
    c.speak();

    return 0;
}


/*
1. Abstraction

    Means hiding complexity and showing only essential details.

    In C++, we achieve it using abstract classes (class with at least one pure virtual function).

    It provides a partial or complete blueprint.

    An abstract class can have:

        pure virtual functions (forces child to override)

        normal functions (implemented)

        data members (variables inside)

    It can even have some working code.


    class Animal {
    public:
        virtual void eat() = 0;  // Pure virtual
        void sleep() {           // Normal function
           std::cout << "Animal sleeping...\n";
      }
};


2. Interface

    Interface is pure abstraction.

    In C++, Interface = class with only pure virtual functions, no variables, no function body (except destructor allowed).

    Interface only specifies what to do, not how to do.
    100% pure blueprint.

    NO implementation allowed inside interface.

    class IShape {
    public:
        virtual void draw() = 0;
        virtual void resize() = 0;
        virtual ~IShape() {}  // Interface can have virtual destructor
    };


*/