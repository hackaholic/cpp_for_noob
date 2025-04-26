#include <iostream>
using namespace std;

void byValue(int x) {
    x += 5;
    cout << "[byValue] x = " << x << ", address = " << &x << endl;
}

void byPointer(int* x) {
    *x += 5;
    cout << "[byPointer] *x = " << *x << ", address = " << x << endl;
}

void byReference(int& x) {
    x += 5;
    cout << "[byReference] x = " << x << ", address = " << &x << endl;
}

int main() {
    int a = 10;
    cout << "[main] a = " << a << ", address = " << &a << endl;

    byValue(a);
    cout << "[main after byValue] a = " << a << endl;

    byPointer(&a);
    cout << "[main after byPointer] a = " << a << endl;

    byReference(a);
    cout << "[main after byReference] a = " << a << endl;

    return 0;
}

/*
 Key Concept Clarification
🔹 Reference (int& x)

    Not a pointer.

    It's like giving another name to the same variable.

    Cannot be null, cannot be reassigned.

    Compiler internally handles it like a pointer, but you use it like a normal variable.

🔹 Pointer (int* x)

    Is a real pointer.

    You must dereference using * to access value.

    Can be null, can be reassigned to point elsewhere.
*/
