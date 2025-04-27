#include <iostream>
#include <functional>
using namespace std;



int main() {

    auto power_lambda = [](const string& s) -> std::function<int(int)> {
        if (s == "square")
        {
            return [](int x) { return x*x;};
        }

        if(s == "cube") {
            return [](int x) {return x*x*x;};
        }
    };

    auto square = power_lambda("square");
    auto cube = power_lambda("cube");

    std::cout << "square of 10 " <<  square(10) << std::endl;
    std::cout << "cube of 10 " <<  cube(10) << std::endl;

}