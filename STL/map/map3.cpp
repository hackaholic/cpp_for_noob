#include <iostream>
#include <map>

using namespace std;

/*
Rules to use Custom Data Types (struct/class) in std::map:

When you use your own struct/class as key in std::map,
👉 you MUST define a way to compare two keys.
Because std::map always sorts keys internally.

How?

    Option 1: Overload the operator< inside your struct/class.

    Option 2: Write a separate Comparator struct/class and pass it to std::map.
*/

struct Pet {
    string name;
    int age;

    bool operator<(const Pet &p) const {
        return this->name < p.name;
    }
};

int main(int argc, char *argv[]) {

    std::map<Pet, int> pet1;

    pet1[{ "Mini", 5 }] = 100;
    pet1[{ "Kiki", 3 }] = 200;
    pet1[{ "Coco", 8 }] = 300;

    for (auto it : pet1) {
        cout << "Pet: " << it.first.name << ", Age: " << it.first.age << ", Value: " << it.second << endl;
    }

    std::cout << "Using lambda \n";
    auto cmp = [](const Pet &p1, const Pet& p2) -> bool {
        return p1.name < p2.name;
    };

    std::map<Pet, int, decltype(cmp)> pet2(cmp);

    pet2[{ "Raya", 5 }] = 100;
    pet2[{ "Niko", 3 }] = 200;
    pet2[{ "Ginger", 8 }] = 300;

    for(auto it: pet2) {
        std:: cout << "Pet: " << it.first.name  << ", Age: " << it.first.age << ", Value: " << it.second << endl;
    }

    return 0;
}