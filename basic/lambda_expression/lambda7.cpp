#include <iostream>
#include <functional>   // // needed for std::function

using namespace std;

// lambda factory

int main() {

    // auto power_lambda = [](const string& s) {
    //     if (s == "square")
    //     {
    //         return [](int x) { return x*x;};
    //     }

    //     if(s == "cube") {
    //         return [](int x) {return x*x*x;};   // deduced return type lambda [](int x)-> int conflicts with previously decuced lambda
    //     }
    // };


    // syntax: std::function<ReturnType(Param1Type, Param2Type, ..., ParamNType)>

    // fix is to use proper return type std::function<int(int)>


    auto power_lambda = [](const string& s)-> std::function<int(int)> {
        if (s == "square")
        {
            return [](int x) { return x*x;};
        }

        if(s == "cube") {
            return [](int x) {return x*x*x;};   // deduced return type lambda [](int x)-> int conflicts with previously decuced lambda
        }
    };

    auto square = power_lambda("square");
    auto cube = power_lambda("cube");

    std::cout << "square of 10 is " <<  square(10) << std::endl;
    std::cout << "cube of 10 is " <<  cube(10) << std::endl;

}