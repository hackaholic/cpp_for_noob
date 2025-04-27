#include <iostream>
#include <memory>
// unique_ptr — One owner, RAII-style (Resource Acquisition Is Initialization)

using namespace std;

class Animal {
public:
    void speak()  {
        std::cout << "Animal Speak!!" << std::endl;
    }

    ~Animal() {
        std::cout << "Animal object destroyed!!" << std::endl;
    }

};

int main(int argc, char *argv[]) {

    // creating unique pointer
    std::unique_ptr<Animal> uptr1 = std::make_unique<Animal>();   //  std::unique_ptr<Animal> ptr1(new Animal())

    // std::unique_ptr<Animal> uptr2 = uptr1;   // Error cant copy

    std::cout << "Address managed by uptr1 -> " << uptr1.get() << std::endl;
    // get() returns raw pointer, what is the address uptr1 is pointing to
    Animal *raw_ptr1 = uptr1.get();

    if (uptr1) {
        std:: cout << "Address managed by uptr1 -> " <<  uptr1.get() << std::endl;
        std:: cout << "Address managed by raw_ptr1 -> " <<  raw_ptr1 << std::endl;
    }

    // moves transfer ownership, but does not delete the object.
    std::unique_ptr<Animal> uptr2 = std::move(uptr1);

    if (!uptr1) {
        std:: cout << "After Move uptr1 is empty, null pointer " << std::endl;
        std:: cout << "Address managed by uptr2 -> " <<  uptr2.get() << std::endl;
    }

    // release() gives raw pointer and removes ownership,  but does not delete the object.
    Animal *raw_ptr2 = uptr2.release();

    if(!uptr2) {
        std:: cout << "After release uptr2 is empty, null pointer" << std::endl;
        std:: cout << "Address managed by raw_ptr2 -> " <<  raw_ptr2 << std::endl;
    }

    // reset assigns new object 
    uptr1.reset(new Animal());
    std::unique_ptr<Animal> uptr3 = std::make_unique<Animal>();

    std:: cout << "Address managed by uptr1 -> " <<  uptr1.get() << std::endl;
    std:: cout << "Address managed by uptr3 -> " <<  uptr3.get() << std::endl;

    std::cout << "Address of uptr1 and uptr2 after swap: " << std::endl;
    uptr1.swap(uptr3);

    std:: cout << "uptr1 -> " << uptr1.get() << std::endl;
    std:: cout << "uptr3 -> " << uptr3.get() << std::endl;

    delete raw_ptr1;

    // delete raw_ptr2   // Error: free(): double free detected in tcache 2
    return 0;

}                               