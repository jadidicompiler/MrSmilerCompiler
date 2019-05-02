
/*
    this file contains
    code about usefull utilities

*/

#include <string>


namespace util{

// create substring from a string
// it cuts the string from the 'begin' to 'end' position
std::string createString(int begin, int end, std::string);


// determines a character is a alphabet character
bool isAlpha(char ch);


// determines a character is a number
bool isNumber(char ch);


}

