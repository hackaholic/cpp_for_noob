#include <iostream>

int main(int argc, char *argv[]) {

    int x = 10, y = 20;
    int &z = x;

    // int &z = NULL;
    
    // &z = y  //Reference cant be NULL or reassigned.
    // Math on reference is not allowed
    
    // reference to reference is not llowed
    // int &&k = z
    return 0;
}