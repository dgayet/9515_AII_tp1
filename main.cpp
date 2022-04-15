#include <iostream>

bool compareString(std::string string1, std::string string2);

void findSubString(std::string ref, std::string target);

void printResults(int * arr, size_t len);

int * appendValueToArray(int * og_arr, size_t len, int value);

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

    findSubString(ref_string, target_string);
    return 0;
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

void findSubString(std::string ref, std::string target){
    size_t ref_len = ref.length(), target_len = target.length();
    size_t i, j, n_matches=0; // for index
    size_t m = -1; // match index
    char ref_ch, target_ch;
    int * index = NULL; // array with index of ocurrences

    for (i = 0, j=0; (i < ref_len) && (ref_len - m + 1 > target_len); i++){
        ref_ch = ref.at(i);
        target_ch = target.at(j);
        if (std::tolower(ref_ch) == std::tolower(target_ch)){
            if (j == 0)
                m = int(i);
            j++;
            if (j == target_len){
                n_matches++;
                if (n_matches == 1){
                    index = new int[1];
                    index[0] = int(m);
                }
                else{
                    index = appendValueToArray(index, n_matches - 1, int(m));
                    // aca puedo perder memoria
                }
                j=0;
            }
        }
        else if (ref.at(i) == target.at(0)){
            m = int(i);
            j = 1;
        }
        else{
            j = 0;
        }
    }

    printResults(index, n_matches);
}

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

int * appendValueToArray(int * og_arr, size_t len, int value){
    int * new_arr = new int[len + 1];
    std::copy(og_arr, og_arr +len, new_arr);
    new_arr[len] = int(value);
    delete og_arr; // signfica algo hacer esto aca??
    return new_arr;
}