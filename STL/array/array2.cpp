#include <iostream>
#include <array>
#include <functional>
#include <algorithm>   // for_each


using namespace std;

int main(int argc, char *argv[]){
    std::array<int, 5> arr1 = {1, 2, 3, 4, 5};

    // iterators

    // begin -> returns an iterator to the beginning
    std::array<int, 5>::iterator start = arr1.begin();

    // returns an iterator to the end
    auto end = arr1.end();

    while(start != end) {
        std::cout << *(start++) << " ";
    }

    std::cout <<std::endl;

    // rbegin -> returns a reverse iterator to the beginning 
    // rend -> returns a reverse iterator to the end

    auto print = [](const int& val) {
        std::cout<< val << " "; 
    };
    
    std::cout << "Reverse order: " << std::endl;
    // for_each  -> UnaryFunc for_each( InputIt first, InputIt last, UnaryFunc f );
    std::for_each(arr1.rbegin(), arr1.rend(), print);
    std::cout <<std::endl;

    return 0;
}