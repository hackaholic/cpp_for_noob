#include <iostream>
#include <array>
using namespace std;

class MyIterator {
    int *ptr;
    int size;

public:
    MyIterator(int *p, int n): ptr(p), size(n) {}

    int * data() { // return pointer to underlying array
        return this->ptr;
    }

    int *begin() {
        return this->ptr;
    }

    inline int front() { // return 1st element
        return *(this->ptr);
    }

    inline int last() { // return last element
        return *(this->ptr + this->size -1);
    }

    inline int *end() {
        return this->ptr + this->size;
    }

    ~MyIterator() {
        delete ptr;
    }

};

int main(int argc, char *argv[]) {

    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};

    MyIterator it(arr, n);

    std::cout << "1st element: " << it.front() <<std::endl;
    std::cout << "Last element: " << it.last() <<std::endl;

    int *begin = it.begin();
    int *end = it.end();

    while(begin != end) {
        std::cout << *(begin++) << std::endl;
    }

    return 0;
}