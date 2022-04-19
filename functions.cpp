#include "functions.h"

char formatChar(char ch){
    char formatted_ch;
    formatted_ch = static_cast<char> (std::tolower(static_cast<unsigned char>(ch) ));
    // next: add support for diacritic characters
    return formatted_ch;
}


void printResults(int * arr, size_t len){
    if (arr == NULL){
        std::cout << "The target text has not been found" << std::endl;
    }
    else{
        std::cout << "The ocurrences are at: ";
        for (size_t i = 0; i < len; i++){
            std::cout << arr[i];
            if (i < len - 1)
                std::cout << ", ";
        }
        std::cout << std::endl;
    }
}


int * appendValueToArray(int * og_arr, size_t len, int value){
    int * new_arr = new int[len + 1];

    for (size_t i = 0; i < len; i++)
        new_arr[i] = og_arr[i];
    new_arr[len] = int(value);
    delete[] og_arr; 
    return new_arr;
}


void findSubString(std::string ref, std::string target){
    size_t ref_len = ref.length(), target_len = target.length();
    size_t i, j, n_matches = 0; // index for reference and target, number of matches
    int m = -1; // match index
    char ref_ch, target_ch;
    int * index = NULL; // array with index of matches

    if (ref_len < target_len)
    {
        std::cout << "Target text is larger than reference text" << std::endl;
        return;
    }

    if(ref.length() == 0 || target.length() == 0)
    {
        std::cout << "One of the texts is empty." << std::endl;
        return;
    }

    for (i = 0, j = 0; (i < ref_len) && ((ref_len - i >= target_len) || (ref_len - m >= target_len)); i++){
        // format both characters before comparing
        ref_ch = formatChar(ref.at(i));
        target_ch = formatChar(target.at(j));
        if (ref_ch == target_ch){ // if characters match
            if (j == 0) // if the first character of the target matches a character of the reference
                m = int(i); // saves the place of the match
            j++;
            if (j == target_len){ // if every character matches consecutively
                n_matches++;
                index = appendValueToArray(index, n_matches - 1, int(m)); // append new match to existing matches
                j=0;
            }
        }
        else // if characters do not match
            j = 0;
    }

    printResults(index, n_matches);
    delete[] index; // frees allocated memory for the positions array
    return;
}