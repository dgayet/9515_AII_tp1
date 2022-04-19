/* ----------- Algoritmos y Programación II - 95.14 ---------
----------------------- Trabajo Práctico N°1 ----------------
-------------- Denise Giselle Gayet, padrón: 100828 --------- */

#include <iostream>
#include "functions.h"


// PRE: receives 2 arguments from CL, first the reference text, then the target text
// POST: -
int main(int argc, char * argv[]) {
    if (argc <3){
        std::cout << "Not enough input arguments" << std::endl;
        return 1;
    }
    else if(argc > 3){
        std::cout << "Too many arguments. Will use first two" << std::endl;
    }

    std::string ref_string{argv[1]};
    std::string target_string{argv[2]}; // turn this into a for, for multiple target strings


   
    findSubString(ref_string, target_string);
    return 0;
}