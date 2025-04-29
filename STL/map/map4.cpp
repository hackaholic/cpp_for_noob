#include <iostream>
#include <map>
#include <string>
using namespace std;

// Pet is now a class (not a struct)
class Pet {
public:
    string name;
    int age;

    // Constructor
    Pet(string n, int a) : name(n), age(a) {}

    // Overload operator< to allow sorting
    bool operator<(const Pet& other) const {
        return name < other.name;   // Sort based on name
    }
};

int main() {
    std::map<Pet, int> pets;

    pets[Pet("Mini", 5)] = 100;
    pets[Pet("Kiki", 3)] = 200;
    pets[Pet("Coco", 8)] = 300;

    for (auto it : pets) {
        cout << "Pet: " << it.first.name << ", Age: " << it.first.age << ", Value: " << it.second << endl;
    }

    return 0;
}
