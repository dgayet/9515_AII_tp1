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

int finSubString(std::string ref, std::string target){
    size_t ref_len = ref.length();
    size_t target_len = target.length();
    size_t i; // for index
    size_t m = -1; // match index
    bool match;

    for (i = 0; i < ref_len - target_len; i++){
        if (ref.at(i) == target.at(0))
            m = i;
            if (i < ref_len - target_len)
                match = compareString()
    }
}