#include <iostream>

// PRE: receives an ASCII character 
// POS: returns the same character in lowercase if it is a non-diacritic letter.
char formatChar(char ch);

// PRE: receives an array and its lenght (number of elements)
// POS: prints the elements of the array to the standard output
void printResults(int * arr, size_t len);

// PRE: receives a dinamyc array of ints and its length, and the value to append to the array
// POS: returns a copy of the original array with "value" appended to it  
//      and frees the allocated memory for the original array 
int * appendValueToArray(int * og_arr, size_t len, int value);

// PRE: receives two strings, ref must be larger than target
// POS: prints the indexes of the referecene text where ocurrences were found
void findSubString(std::string ref, std::string target);