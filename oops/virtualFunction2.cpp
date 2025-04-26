#include <iostream>

using namespace std;

/*
When you mark a function virtual,
compiler thinks:

    "Hold on! This function might be overridden.
    Don't decide now. I'll leave it to runtime to check the actual object."

    With Virtual,  a vtable is created inside class.
    vtable contains all virtual functions' addresses in order.

    If an object of that class is created then a virtual pointer (VPTR) is inserted as a data member of the class to point to the VTABLE of that class.
    vptr is a hidden pointer inside object that points to the starting address of the vtable for its class.
    Virtual function calls use the vptr to lookup the correct function at runtime using a known offset.

    Calling a->function() means:

    Look at vptr → jump to vtable → pick function at correct index → CALL.
*/

class Animal {
public:
    virtual void speak() {
        std::cout << "Animal Sound" << std::endl;
    }
    
    virtual void run() {
        std::cout << "Animal running" << std::endl;
    }

    virtual void eat() {
        std::cout << "Animal eating" << std::endl;
    }
};

/*
Animal vtable 

Animal_vtable:
+----------------------+
| speak() -> Animal::speak() |
+----------------------+
| run() -> Animal::run()     |
+----------------------+
| eat() -> Animal::eat()     |
+----------------------+

*/

class Cat: public Animal {
public:
    void speak() override {
        std::cout<< "Meow Meow!!" << std::endl;
    }
};

/*
Cat_vtable:
+----------------------+
| speak() -> Cat::speak() |
+----------------------+
| run() -> Animal::run()  |   (if not overridden in Cat)
+----------------------+
| eat() -> Animal::eat()  |   (if not overridden in Cat)
+----------------------+

*/


class Dog: public Animal {
public:
    void speak() override {
        std::cout<< "Woff Woff!!" << std::endl;
    }
};

int main(int argc, char*argv[]) {

    Animal *a = new Cat();

    a->speak();

    Dog d;

    a = &d;

    a->speak();
    return 0;

}

/*
1. Pointer stores address (not the object itself)

    Animal* a = new Cat();

        a holds the address of a Cat object.

    Later, a = &d;

        Now a holds the address of a Dog object.

2. Why virtual is needed

    Compiler only knows type of pointer (Animal*).

    It cannot predict which derived class (Cat, Dog, etc.) at compile time.

    So, it needs help to figure out at runtime which speak() function to call.


3. What virtual keyword does

    It tells compiler:

        "Don't call directly based on pointer type,
        at runtime, use the real object type (Cat, Dog) to decide."

4. Runtime behavior: Vtable lookup

    When a->speak() is called:

        Look into object's vtable (a table of function pointers).

        Pick the correct version of speak() dynamically.

5. Without virtual

    Without virtual,
    a->speak() would always call Animal's speak(),
    because compiler binds it early based on the type Animal*.

    (This is called early binding / static binding.)

6. With virtual

    With virtual, a->speak() does a vtable lookup at runtime.

    (This is called late binding / dynamic binding.)

*/


