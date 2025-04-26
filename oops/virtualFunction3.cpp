#include <iostream>
#include <string>

using namespace std;
/*
✅ override is optional in C++.
✅ But it is highly recommended (best practice).
*/



class Animal {
public:
    virtual void speak(string s) {
        std::cout <<  "Animal Speak " << s << std::endl;
    }
};


/*
f you don't use override,
C++ assumes you are just writing a new function in child — it doesn't even check if you intended to override or not.

If you accidentally mismatch signature, it will not give any error.
*/

class Cat: public Animal {
public:
    void speak() {   // no error withour override keyword, as it thing its the new function
        std::cout << "Memow meow!!" << std::endl;
    }
};

// class Cat: public Animal {
//     public:
//         void speak() override {   // now compiler will check and give compile time error
//             std::cout << "Memow meow!!" << std::endl;
//         }
//     };
    
int main(int argc, char *argv[]) {

    Cat c;
    c.speak();
}

