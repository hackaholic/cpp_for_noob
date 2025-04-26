#include <iostream>

using namespace std;

/*
What is Object Slicing?

Object slicing happens when you assign an object of a derived class to an object of a base class. 
The derived class object "slices off" its derived part and only the base class part is copied over to the base class object.

How to prevent object slicing?

You need to use pointers or references to base class objects if you want to retain the derived class part.
*/


class Animal {
    public:
        virtual void speak() {
            cout << "Animal speaks" << endl;
        }
    };
    
class Dog : public Animal {
public:
    void speak() {
        cout << "Dog barks" << endl;
    }
    void wagTail() {
        cout << "Dog wags tail" << endl;
    }
};
    
int main() {
    Dog dog;
    Animal animal = dog;  // Object slicing
    animal.speak();  // Output: Animal speaks (not Dog barks)
    // animal.wagTail();  // Error: wagTail doesn't exist in Animal

    // fix is to define pointer type
    Animal *animal1 = new Dog();
    animal1->speak();


}
    