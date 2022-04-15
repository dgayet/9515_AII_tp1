#include <iostream>

bool compareString(std::string string1, std::string string2);

int findSubString(std::string ref, std::string target);

// we can use tolower, HAVE to have preconditions and postconditions
int main(int argc, char * argv[]) {
    // turn this into a function

    if (argc <3){
        std::cout << "Not enough input arguments" << std::endl;
        return 1;
    }
   
    std::string ref_string{argv[1]};
    std::string target_string{argv[2]}; // turn this into a for, for multiple target strings
   
    //bool c;
    //c = compareString(ref_string, target_string);
    //std::cout << c << std::endl;

    int index = findSubString(ref_string, target_string);
    if (index == -1){
        std::cout << "The target string has not been found" << std::endl;
    }
    else{
        std::cout << "There is an ocurrence in the index: " << index << std::endl;
    }
}

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

int findSubString(std::string ref, std::string target){
    size_t ref_len = ref.length();
    size_t target_len = target.length();
    size_t i, j; // for index
    size_t m = -1; // match index
    char ref_ch, target_ch;

    // three conditions for the for clause 


    
    for (i = 0, j=0; (i < ref_len) && (j < target_len) && (ref_len - m + 1 > target_len); i++){
        ref_ch = ref.at(i);
        target_ch = target.at(j);
        if (std::tolower(ref_ch) == std::tolower(target_ch)){
            if (j == 0)
                m = i;
            j++;
        }
        else if (ref.at(i) == target.at(0)){
            m = i;
            j = 1;
        }
    }

    if (j == target_len)
        return int(m);
    else
        return -1;
}