#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    int *a = new int;   // declearing pointer
    *a = 10;
    std::cout << "a: " << *a << std::endl;
    delete a; // deleting the allocated sapce, same like free in C

    int *b = new int(11);     // decleared pointer and initialized with value 11
    std::cout << "b: " << *b << std::endl;
    delete b;

    int *arr = new int[5];  // declearing dynamic array pointer of size 5
    std::cout << "from arr:\n";
    for(int i=0;i<5;i++) {
        arr[i] = i;
        cout << *(arr+i) << " : " <<  arr[i] << std::endl;    
    }
    delete[] arr;
    return 0;
}