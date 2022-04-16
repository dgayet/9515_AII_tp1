#include "functions.h"

// Preconditions: 
// Postconditions: 
bool compareString(std::string string1, std::string string2){
    size_t len1 = string1.length();
    size_t len2 = string2.length();

    if (len1 != len2){
        return false;
    }

    for (size_t i=0; i < len1 ; i++){
        char ch1 = string1.at(i);
        char ch2 = string2.at(i);
        if (std::tolower(ch1) != std::tolower(ch2)) //key insenstive
            return false;
    } 
    return true;
}


// Preconditions: 
// Postconditions: 
char formatChar(char ch){
    char formatted_ch;
    formatted_ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
    // add support for diacritic characters
    return formatted_ch;
}


// Preconditions: 
// Postconditions: 
void findSubString(std::string ref, std::string target){
    size_t ref_len = ref.length(), target_len = target.length();
    size_t i, j, n_matches=0; // index for reference and target, number of matches
    int m = -1; // match index
    char ref_ch, target_ch;
    int * index = NULL; // array with index of matches

    for (i = 0, j=0; (i < ref_len) && ((ref_len - i >= target_len) || (ref_len - m >= target_len)); i++){
        ref_ch = formatChar(ref.at(i));
        target_ch = formatChar(target.at(j));
        if (ref_ch == target_ch){
            if (j == 0)
                m = int(i);
            j++;
            if (j == target_len){
                n_matches++;
                // change to an incremental memory assignment
                index = appendValueToArray(index, n_matches - 1, int(m)); // aca puedo perder memoria
                j=0;
            }
        }
        else
            j = 0;
    }

    printResults(index, n_matches);
    delete[] index;
}


// Preconditions: 
// Postconditions: 
void printResults(int * arr, size_t len){
    if (arr == NULL){
        std::cout << "The target string has not been found" << std::endl;
    }
    else{
        std::cout << "The ocurrences are at: ";
        for (size_t i=0; i < len; i++){
            std::cout << arr[i];
            if (i < len - 1)
                std::cout << ", ";
        }
        std::cout << std::endl;
    }
}


// Preconditions: 
// Postconditions: 
int * appendValueToArray(int * og_arr, size_t len, int value){
    int * new_arr = new int[len + 1];
    std::copy(og_arr, og_arr + len, new_arr);
    new_arr[len] = int(value);
    delete[] og_arr; // esto esta efectivamente borrando?
    return new_arr;
}