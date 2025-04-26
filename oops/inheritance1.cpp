/*
What’s Inheritance?

Just like in real life — a child inherits stuff from a parent.
🔹 Code-wise:

A child class (aka derived class) reuses code from a parent class (aka base class).
*/

#include <iostream>

using namespace std;
class Employee {
public:
    virtual void work() {
        std::cout << "Employee working..." << std::endl;    
    }
};
    
class Manager : public Employee {
public:
    virtual void work() override {             
        cout << "Manager planning..." << endl;
    }
};

int main(int argc, char *argv[]) {
    Employee* e = new Manager();
    e->work();  //  Without `virtual`  ERROR -> inheritance1.cpp:22:10: error: ‘void Manager::work()’ marked ‘override’, but does not override
                // With `virtual` → prints "Manager planning"
    
    delete e;

    return 0;
}

/*
❓ What if you don't have the source code to base class?

    "Can I override a function if it's not virtual in the base and I can't modify the base?"

Unfortunately... No. 😔
*/
    