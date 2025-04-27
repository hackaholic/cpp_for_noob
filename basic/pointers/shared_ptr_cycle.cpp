#include <iostream>
#include <memory>

using namespace std;

class B; // forward declaration

class A {
public:
    std::shared_ptr<B> b_ptr;
    ~A() { std::cout << "A destroyed" << std::endl; }

};

class B {
public:

    std::shared_ptr<A> a_ptr;
    ~B() { std::cout << "B destroyed" << std::endl; }
    
};

int main(int argc, char *argv[]) {

    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b(new B());

    std::cout << "a use_count = " <<  a.use_count() << std::endl;
    std::cout << "b use_count = " <<  b.use_count() << std::endl;

    std::cout << "a->b_ptr use_count = " <<  a->b_ptr.use_count() << std::endl;
    std::cout << "b->b_ptr use_count = " <<  b->a_ptr.use_count() << std::endl;

    a->b_ptr = b;
    b->a_ptr = a;

    std::cout << "a use_count = " <<  a.use_count() << std::endl;
    std::cout << "b use_count = " <<  b.use_count() << std::endl;
    std::cout << "a->b_ptr use_count = " <<  a->b_ptr.use_count() << std::endl;
    std::cout << "b->a_ptr use_count = " <<  b->a_ptr.use_count() << std::endl;


    /*
    So, both objects' use_count never be comes 0.

     Destructor will never be called → MEMORY LEAK!

    Fix:  When two objects point to each other,
    at least one side MUST use weak_ptr
    to avoid memory leaks!
    */


    return 0;
}