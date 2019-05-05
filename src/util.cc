

#include "util.h"

namespace util{

// create std::string word from beginnig and end index of the text
std::string createString(int begin, int end, std::string pstr){
    int pstr_length = end - begin + 1;


    char* str = new char[pstr_length];
    int l = 0;
    for (int i = begin; i <= end; i++){
        str[l++] = pstr[i]; 
    }
    str[l] = '\0';

    std::string new_str = str;
    delete [] str;
    
    return new_str;
}

// this determines a character is alphabet character
bool isAlpha(char ch){
    if ((ch > 64 && 
         ch < 91) ||
        (ch > 96 && 
         ch < 122)) {

        return true;
    }
    else {
        return false; 
    }
}


// this determines a character is number
bool isNumber(char ch){
    return (ch > 47 && ch < 58)? true: false;
}


// convert a string to integer
int convertToNumber(std::string num){
    int n = 0;

    for(int i = 0; i < num.size(); i++){
	// since number zero is in 48 place of ascii table
	n = n * 10 + (num[i] - 48); 
    }

    return n;
}


}
