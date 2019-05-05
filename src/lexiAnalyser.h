
/*
    this file contains the first
    phase of the compiler which is
    lexical analyser or scanner


    note:
        this code is using 
        a combination of 
        google code style
        and MrSmiler preference
*/

/*
    Todo:
        fix Token class
        token_value has memmory 
        consumtion issue
        if type is not string

        

*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "util.h"
#include "token.h"


// first phase of compiler
class LexicalAnalyser {
    private: 
        // programming language text
        std::string text; 

        // symbolTable
        std::vector<std::string> symbol_table;

        // symbol table index
        int st_index = -1;
        
        // a array of tokens
        std::vector<Token*> tokens;
        
        // state of a automata
        int state;

        // pointer to the text index;
        int forward;

        // pointer to the beginning of a word
        int word_begin;

        // current character
        char current_char;

        // the token type
        std::string token_type;


        // error message
        std::string error;
        // increment the text pointer
        int nextChar(){
            if (this->state != 9999){
                this->forward++;     
            }
            this->current_char = this->text[this->forward];
            return this->current_char;
        }

        // get current character from text
        char getChar(){
            return this->current_char; 
        }

        inline void goFinal(int state, std::string str){
            this->forward--;
            this->state = state;
            this->token_type = str;
        }


    public:

        LexicalAnalyser(char* fileContent) {
            this->text = fileContent; 
            this->state = 0;
            this->forward = -1;
        }

        // scan the file
        void scan();


	// print tokens on the console
        void printTokens();


};


