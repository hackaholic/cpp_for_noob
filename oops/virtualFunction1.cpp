#include <iostream>

using namespace std;

/*

Overriding (same function name in child class) can happen without virtual when you call using the object directly.

Virtual functions matter when calling through base class pointer/reference.
When directly calling through child object, compiler binds correctly anyway.

*/

class Animal {
public:
    void speak() {   // no virtual here
        std::cout << "Animal Sound" << std::endl;
    }
};

class Cat: public Animal {
public:
    void speak() {
        std::cout<< "Meow Meow!!" << std::endl;
    }
};

int main(int argc, char *argv[]) {

    // compiler knows c is of type Cat, so it directly binds Cat::speak() at compile time.
    Cat c;
    c.speak();   // early binding (static binding) function is selected at compile time

    /*  
    Problem without virtual happens only when:
    use base class pointers or references to point to child class objects.
    */
    Animal *a = new Cat();
    a->speak();    
    /* ⚡ OOPS! Calls Animal::speak(), not Cat::speak() without virtual
    so without virtual, compiler binds Animal::speak() at compile time.
    Because at runtime, the real object is a Cat.
    But the compiler didn't know that — it trusted the pointer type.
    */

    return 0;
}
