#include <iostream>
#include <memory>

using namespace std;

class B;  // forward declaration

class A {
public:
    std::shared_ptr<B> b_ptr;

    ~A() {std::cout << "A destroyed" << std::endl;}
};

class B {
    public:
        std::weak_ptr<A> a_ptr;   // make one of them weak pointer
        ~B() {std::cout << "B destroyed" << std::endl;}
};


int main(int argc, char *argv[]) {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

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

    return 0;
}

