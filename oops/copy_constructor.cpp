#include <iostream>

using namespace std;

class Bag {
    int size;
    int *data;
public:
    Bag(int s): size(s) {
        data = new int[size];
        for(int i =0;i<size;i++) data[i] = i;
    }

    Bag(const Bag& other) {
        size = other.size;
        data = new int[size];
        for(int i =0;i<size;i++) data[i] = other.data[i];
    }

    Bag& operator=(const Bag& other) {
        if(this != &other) {
            size = other.size;
            data = new int[size];
            for(int i =0;i<size;i++) data[i] = other.data[i];
        }

        return *this;
    }

    ~Bag() {
        delete[] data;
    }

    void show() {
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main(int argc, char *argv[]) {
    Bag b1(5);
    Bag b2(b1); // copy constructor

    Bag b3 = b2;   // copy constructor
    b1 = b2;        // copy assignment
    b2.show();
    b3.show();

    return 0;
}