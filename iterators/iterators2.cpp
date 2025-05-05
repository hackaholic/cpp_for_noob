#include <iostream>

using namespace std;

class MyIterator {
    int *ptr;
public:
    MyIterator(int *p):  ptr(p) {}
    
    int& operator*() {
        return *(this->ptr);
    }

    // pre increment
    MyIterator& operator++() {
        ++(this->ptr);
        return *this;
    }

     // Inequality comparison
    bool operator!=(const MyIterator& other) const {
        return this->ptr != other.ptr;
    }

};

class MyContainer {
    int *data;
    int size;
public:
    MyContainer(int n): size(n) {
        data = new int[this->size];
    }

    int&  operator[](int pos) {
        return this->data[pos];
    }

    MyIterator begin() { return MyIterator(this->data);}
    MyIterator end() { return MyIterator(this->data + this->size);}

};


int main(int argc, char *argv[]) {

    MyContainer container(5);

    for(int i=0;i<5;i++) {
        container[i] = i*2;
    }

    for(auto val: container) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    /*
    auto __begin = container.begin();
    auto __end = container.end();

    for (; __begin != __end; ++__begin) {
        int val = *__begin;
        std::cout << val << " ";
}

    */

    return 0;
}