#include <iostream>
#include <array>

using namespace std;

/*

array<Type, Size> arr;

*/

int main(int argc, char *argv[]) {

    array<int, 0> arr1;
    array<int, 3> arr2 = {4, 5, 6};
    array<int, 10> arr3 = {1, 2, 3, 4, 5};

    // Element access

    // operator [] access specified element 
    std::cout << "arr2[0]: " << arr2[0] << std::endl;
    arr2[0] = 10;
    std::cout << "arr2[0]: " << arr2[0] << std::endl;
    
    // at -> Returns a reference to the element at specified location pos, with bounds checking.
    std::cout << "at(2): " <<  arr2.at(2) << std::endl;
    arr2.at(2) = 88;
    std::cout << "at(2): " <<  arr2.at(2) << std::endl;

    int &k =  arr2.at(2);

    // data -> Returns a pointer to the underlying array serving as element storage

    int *p = arr3.data();
    for(int i = 0;i<arr3.size();i++) {
        std::cout << *(p+i) << ((i<(arr3.size()-1))? " ":"\n");
    }

    // front -> return 1st element
    std::cout << "front: " << arr2.front() <<std::endl;

    // back -> return 1st element
    std::cout << "last: " << arr2.back() <<std::endl;

    // Capacity 

    // empty -> if empty return 1 else 0
    std::cout<< "arr1 is empty?: " << arr1.empty() << std::endl;
    std::cout<< "arr2 is empty?: " << arr2.empty() << std::endl;

    // size returns the number of elements in arr
    std::cout << "size: arr2: " << arr2.size() << std::endl;
    std::cout << "size: arr3: " << arr3.size() << std::endl;

    std::cout << "max_size: arr2: " << arr2.max_size() << std::endl;
    std::cout << "max_size: arr3: " << arr3.max_size() << std::endl;

    return 0;
}