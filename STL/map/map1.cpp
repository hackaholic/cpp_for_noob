#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
    map<string, int> age;

    //Insert operator=
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

    // Access operator[]
    cout << "Mini's age: " << age["Mini"] << endl;

    for(auto &pair : age) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // lookup

    // check key exits returns 0 or 1
    std::cout << age.count("Shiro") << std::endl;   //  python key in dict

    /*
    find -> returns An iterator to the requested element
    Expression                  | Purpose
    auto it = m.find(key)       | Get iterator to (key,value)
    it->first                   | Key
    it->second                  | Value
    if (it != m.end())          | Check if found

    .find(key) fails (key not found),
    then it == m.end().
    */ 
    string key = "Simbha";
    map<string, int>::iterator search = age.find(key);

    if(search != age.end()) {
        std::cout << "key: " << search->first << ", " << "value: " << search->second << std::endl;
    }
    else {
        std::cout << key <<" not found" << std::endl;
    }

    return 0;
}