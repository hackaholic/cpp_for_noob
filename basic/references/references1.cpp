#include <iostream>
using namespace std;

void test(int& ref) {
    cout << "Inside test: " << ref << " (ref address: " << &ref << ")" << endl;
}

int main() {
    int x = 42;
    cout << "Before test: " << x << " (x address: " << &x << ")" << endl;
    test(x);
    return 0;
}
