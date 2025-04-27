#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    // Lambdas Returning Lambdas (Higher-Order Functions)
    auto multiply_times = [](int factor) {
        return [=](int times) -> int { 
            return factor *times;
        };
    };

    auto times2 = multiply_times(2);
    std::cout << times2(5) << std::endl;
    return 0;
}