
/*
    this program only finds 
    identifiers of a given programming language
*/


#include <iostream>
#include <string>
#include <vector>

// macros
#define print(i) std::cout << (i) << std::endl

std::string createString(int, int, std::string);
bool isAlpha(char);
bool isNumber(char);


int main() {

    // sample programming lanugage code
    std::string prog = "int variable = 10; if (10 > 5) anotherValue++; // do something}";

    // autamata state number
    short int state = 0;

    // beginning of the word index
    int word_begin = 0;
    
    // a array for storing tokens
    std::vector<std::string> tokens;

    // loop over the prog string characters
    for (int i = 0; i < prog.size()+1; i++) {
        switch (state) {

            // automata state 0
            case 0:
                if (isAlpha(prog[i])) {
                    state = 1;
                }
                else {
                    word_begin = i + 1;
                }

                break;

            // automata state 1
            case 1: 
                if (isAlpha(prog[i]) || isNumber(prog[i])) {
                    state = 1;
                }
                else {
                    state = 2;          
                }

            break;

            // automata state 2
            case 2:
                i--;
                tokens.push_back(createString(word_begin, i, prog));
                word_begin = i + 1;
                state = 0;
                break;
        }
    }

    for (int i = 0; i < tokens.size(); i++){
        print(tokens[i]);   
    }

    return 0;
}

// create std::string word from beginnig and end index of the text
std::string createString(int begin, int end, std::string pstr){
    int pstr_length = end - begin + 1;


    char* str = new char[pstr_length];
    int l = 0;
    for (int i = begin; i < end; i++){
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


