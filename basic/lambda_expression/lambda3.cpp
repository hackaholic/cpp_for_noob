#include <iostream>

using namespace std;

/*
Lambda Captures:
Syntax     | Meaning
[=]        | Capture everything by value
[&]        | Capture everything by reference
[x]        | Capture only x by value
[&x]       | Capture only x by reference
[=, &y]    | Capture everything by value except y by reference
[&, x]     | Capture everything by reference except x by value

*/

int main() {

    // [=]        | Capture everything by value
    int x = 10;
    int y = 20;

    auto capture_all_value  = [=]() {
        std::cout << "x = " << x << std::endl << "y = " << y << std::endl;
        int x = 30;
        int y = 40;
    };

    capture_all_value();
    std::cout << "After capture_all_value call, no modification on x and y" <<  std::endl;
    std::cout << "x = " << x << std::endl << "y = " << y << std::endl;

    // [&]        | Capture everything by reference

    auto capture_all_by_ref  = [&]() {
        x = 30;
        y = 40;
    };

    capture_all_by_ref();
    //std:cout << std::endl; 
    std::cout << "After capture_all_by_ref call, x and y modified" <<  std::endl;
    std::cout << "x = " << x << std::endl << "y = " << y << std::endl;
    
    return 0;
}