#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    // lambda with parameter
    auto add = [](int a, int b) {
        return a+b;
    };

    std::cout << add(2,3) <<  std::endl;

    // lambda with return type

    auto concat = [](string s1, string s2) -> string {
        return s1 + " " + s2;
    };

    std::cout << concat("Oreo", "Shiro") <<  std::endl;
    return 0;
}