#include <iostream>

using namespace std;


int main(auto argc, auto argv) {

    auto x = 5;          // int
    auto name = "John";  // const char*
    auto pi = 3.14;      // double

    // C  int *ptr = NULL
    int *ptr = nullptr; // nullptr is type-safe and avoids ambiguity.

    vector<int> arr =  {1,2,3};

    for (auto num: arr) {
        std::cout << num << std::endl;
    }
    return 0;
}