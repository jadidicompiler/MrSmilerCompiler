
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
        void printTokens();


};

// print the tokens in a human readable format
void LexicalAnalyser::printTokens(){

    for(int i = 0; i < this->tokens.size(); i++){
        std::string token_type = this->tokens[i]->getTokenType();
        int token_value = this->tokens[i]->getTokenValue();
        std::string value;
        char ch;
        if (token_type == "id"){
            value = this->symbol_table[token_value]; 
        }
        else if( token_type == "num" || token_type == "kw" || token_type == "sep"){
            value = this->tokens[i]->getTokenValueStr(); 
        }
        else if(token_type == "op"){
            value = "\'"+ this->tokens[i]->getTokenValueStr() + "\'"; 
        }
        else {
            value = token_value; 
        }
        std::cout << "<"<< token_type <<", "<< value << ">" << " "; 
        std::cout << std::endl;
    }

}

void LexicalAnalyser::scan(){

    // loop over the text until the end of text
    bool is_error = 0;
    bool is_single = false;
    std::string str;
    while(this->nextChar() && !is_error){

        // current character
        char ch = this->getChar();

        // automata implemention
        switch(this->state){
            // automata state 0
            case 0:
               
                if (isAlpha(ch)) {
                    this->state = 1;  
                }
                else if (ch == '*' || ch == '/' ||
                         ch == '%' || ch == '!' ||
			 ch == '=') {
                    
                    this->state = 2;
                }
                // else if (ch == '=') this->state = 3; 
                else if (ch == '+') this->state = 4;
                else if (ch == '-') this->state = 5;
                else if (isNumber(ch)) this->state = 12;
                else if (ch == '<') this->state = 6;
                else if (ch == '>') this->state = 7;
                else if (ch == '&') this->state = 8;
                else if (ch == '|') this->state = 9;
                else if (ch == '?' || ch == ':'){
                    is_single = true;
                    this->state = 9999;
                    this->token_type = "op";
                } 
                else if (ch == '{' || ch == '}' ||
                         ch == '[' || ch == ']' || 
                         ch == '(' || ch == ')' ||
                         ch == ';') {

                    is_single = true;
                    this->state = 9999;
                    this->token_type = "sep";
                }

                else {
                    this->word_begin = this->forward + 1;
                }
                
                break;

            // automata state 1
            case 1: 

                if (isAlpha(ch) || isNumber(ch)) {
                    this->state = 1;  
                }
                else {
                    this->state = 9999;  
                    this->token_type = "id";
                    // this->goFinal();
                }

                break;

            // automata state 2
            case 2:
                
                if (ch == '='){
                    this->state = 333; 
                }
                else {
                    this->state = 9999; 
                    this->token_type = "op";
                }

                break;

            // automata state 3
            /* case 3: */
            /*     if (ch == '=') this->state = 333; */
            /*     else { */
            /*         this->state = 9999; */
            /*         this->token_type = "op"; */ 
            /*     }; */

            /*     break; */

            // automata state 4
            case 4:
                if (ch == '+' || ch == '=') this->state = 333;
                else if (isNumber(ch)) this->state = 12;
                else {
                    this->state = 9999;
                    this->token_type = "op"; 
                }

                break;

            // automata state 5
            case 5:
                if (ch == '-' || ch == '=') this->state = 333;
                else if (isNumber(ch)) this->state = 12;
                else {
                    this->state = 9999;
                    this->token_type = "op"; 

                }
                
                break;
            // automata state 6
            case 6:
                if (ch == '<' || ch == '=') this->state = 333;
                else {
                    this->state = 9999;
                    this->token_type = "op"; 
                }

                break;

            // automata state 7
            case 7:
                if (ch == '>' || ch == '=') this->state = 333;
                else {
                    this->state = 9999;
                    this->token_type = "op"; 
                }

                break;

            // automata state 8
            case 8:
                if (ch == '&') state = 333;
                else {
                    this->state = 9999;
                    this->token_type = "op"; 
                }

                break;

            // automata state 9
            case 9:
                if (ch == '|') state = 333;
                else {
                    this->state = 9999;
                    this->token_type = "op"; 
                }

                break;
            

            // automata state 12
            case 12:
                if (isNumber(ch)) this->state = 12;
                else if(ch == '.') this->state = 122;
                else {
                    this->state = 9999;
                    this->token_type = "num";
                } 

                break;

            // automata state 122
            case 122:
                if (isNumber(ch)) this->state = 1222;
                else {
                    this->state = -1; 
                    this->error = "invalid number ";
                }
                 
                break;

            // automata state 333
            case 333:
                this->state = 9999;
                this->token_type = "op";

                break;

            // automata state 1222
            case 1222:
                if (isNumber(ch)) this->state = 1222; 
                else {
                    this->state = 9999;
                    this->token_type = "num";
                }

                break;

            // automata state 9999
            case 9999: 
                Token* token;
                //
                if (!is_single){
                    this->forward--;
                }
                is_single = false;
                str = createString(this->word_begin,
                                   this->forward,
                                   this->text);

                /* if (this->token_type == "id") { */
                    
                /*     bool is_keyword = false; */
                /*     // check if the identifier is a keyword */
                /*     int length = sizeof(KEYWORDS)/sizeof(KEYWORDS[0]); */
                /*     for(int i = 0; i < length; i++){ */
                /*         if (str == KEYWORDS[i]){ */
                /*             is_keyword = true; */ 
                /*             break; */
                /*         } */
                /*     } */

                /*     if (is_keyword) { */
                /*         token = new Token("kw", str); */
                /*     } */
                /*     else { */
                /*         this->symbol_table.push_back(str); */
                /*         token = new Token(this->token_type, ++this->st_index); */
                /*     } */
                /* } */
                /* else { */
                /*     token = new Token(this->token_type, str); */
                /* } */
		int value;
		if (this->token_type == "num"){
		   // convert str to number	
		   value = convertToNumber(str);
		}                
		else {
		    // find the str in token list
		    // if it was not there put the token
		    // in the symbole table
		}

		token = new Token(value,)

                this->tokens.push_back(token);
                this->word_begin = this->forward + 1;
                this->state = 0;


                break;

            // error state
            case -1: 
                str = createString(this->word_begin,
                                       this->forward,
                                       this->text);
                // print the error message
                std::cout << this->error << str;

                // stop the loop
                is_error = 1;
                break;
        }
    } 
}


