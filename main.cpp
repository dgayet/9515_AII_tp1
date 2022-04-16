#include <iostream>
#include "functions.h"


// Preconditions: 
// Postconditions: 
int main(int argc, char * argv[]) {
    if (argc <3){
        std::cout << "Not enough input arguments" << std::endl;
        return 1;
    }
   
    std::string ref_string{argv[1]};
    std::string target_string{argv[2]}; // turn this into a for, for multiple target strings
   
    findSubString(ref_string, target_string);
    return 0;
}