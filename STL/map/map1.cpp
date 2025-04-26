#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
    map<string, int> age;

    //Insert
    age["Mini"] = 9;
    age["Coco"] = 9;
    age["DOra"] = 8;
    age["Oreo"] = 8;
    age["Shiro"] = 6;
    age["Batman"] = 6;
    age["Kiki"] = 6;
    age["Raya"] = 6;
    age["Niko"] = 6;
    age["Ginger"] = 6;
    age["Chika"] = 1;
    age["Tj"] = 1;
    age["Suri"] = 1;

    // Access
    cout << "Mini's age: " << age["Mini"] << endl;

    for(auto &pair : age) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // check key exits returns 0 or 1
    std::cout << age.count("Shiro") << std::endl;   //  python key in dict

    return 0;
}