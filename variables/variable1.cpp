#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string name;
    std::cout <<"Enter name: ";
    std::cin >> name;
    cout << "Hello, " << name << "!" << endl;

    std:: getline(cin, name);
    cout << "Hello again, " << name << "!" << endl;
    return 0;
}