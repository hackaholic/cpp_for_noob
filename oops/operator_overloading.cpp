#include <iostream>

class Complex {
    int i;
    int j;

public:
    Complex (int a, int b) {
        this->i = a;
        this->j = b;
    }

    void show() {
        std::cout << i << "+" << j << "i"<< std::endl;
    }

    Complex operator+(const Complex &other) {
        return Complex(this->i+ other.i, this->j+other.j);
    }
};


int main(int argc, char *argv[]) {
    Complex c1(1, 2);
    Complex c2(3,4);
    c1.show();
    c2.show();

    Complex c3 = c1 + c2;
    c3.show();

    return 0;
}