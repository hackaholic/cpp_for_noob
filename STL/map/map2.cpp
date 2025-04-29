#include <iostream>
#include <map>
#include <functional>

using namespace std;

/*
template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>
> class map;

std::map already uses std::less<Key> by default. ascending order

That means:
➔ It sorts keys in ascending order using the < operator.

*/


// Comparator	Must be a callable object (struct, class, or lambda)
struct CompateByLengthBuggy {
    bool operator() (const string& a, const string& b) {
        return a.length() < b.length();
    }
};

/*
why Buggy
If two keys have same length, then:

    Map thinks they are equal!

    So insertion overwrites the previous key!

fix: If lengths equal, then compare strings alphabetically (a < b).

*/

struct CompateByLength {
    bool operator() (const string& a, const string& b) {
        if(a.length() == b.length())  // break tie
            return a < b;
        return a.length() < b.length();
    };
};

int main(int arc, char *argv[]) {
    std::map<int, string> m = {{0, "Mini"}, {2, "RaYA"}, {1, "Kiki"}};

    for(auto it: m) {
        std:: cout << "key: " << it.first << ", value: " <<  it.second << std::endl;
    }


    // using struct
    std::map<string, int, CompateByLengthBuggy> fruits;
    fruits["apple"] = 1;
    fruits["kiwi"] = 2;
    fruits["banana"] = 3;
    fruits["pear"] = 4;
    fruits["plum"] = 5;

    std::cout <<  std::endl << "Buggy Comparator:" << std:: endl;
    for (auto it: fruits) {
        std:: cout << "key: " << it.first << ", value: " <<  it.second << std::endl;
    }

    std::map<string, int, CompateByLength> fruits1;
    fruits1["apple"] = 1;
    fruits1["kiwi"] = 2;
    fruits1["banana"] = 3;
    fruits1["pear"] = 4;
    fruits1["plum"] = 5;

    std::cout <<  std::endl << "Fixed Comparator:" << std:: endl;
    for (auto it: fruits1) {
        std:: cout << "key: " << it.first << ", value: " <<  it.second << std::endl;
    }


    /* 
    using lambda
    Concept                                            |   Details
    auto cmp = [](...) {}                              | Define a comparator lambda
    decltype(cmp)                                      | Capture the lambda type
    map<string, int, decltype(cmp)> mymap(cmp);        | Pass comparator at map construction time
    */ 


    // compating on last char of string :)
    auto cmp = [](const string &a, const string &b) -> bool {
        return a[a.length()-1] <  b[b.length()-1];
    };

    std::map<string, int, decltype(cmp)> fruits2(cmp);

    fruits2["apple"] = 1;
    fruits2["kiwi"] = 2;
    fruits2["banana"] = 3;
    fruits2["pear"] = 4;
    fruits2["plum"] = 5;

    std::cout <<  std::endl << "Using lambda sorting on last char of string" << std:: endl;
    for (auto it: fruits2) {
        std:: cout << "key: " << it.first << ", value: " <<  it.second << std::endl;
    }



    return 0;
}