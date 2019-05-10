#include "lexiAnalyser.h"
#include "token.h"
#include "util.h"

// print the tokens in a human readable format
void LexicalAnalyser::printTokens(){

    for(int i = 0; i < this->tokens.size(); i++){
        std::string token_type = this->tokens[i]->getType();
        int token_value = this->tokens[i]->getValue();
	
	if(token_type == "id"){
	    std::cout << "<"<< token_type <<", "<< this->symbol_table[token_value ]<< ">" << " "; 
	}
	else if(token_type == "num"){
	    std::cout << "<"<< token_type <<", "<< token_value << ">" << " "; 
	}
	else {
	    std::cout << "<"<< token_type <<", '"<< TokenList::getTokenString(token_value)<< "'>" << " "; 
	}
        std::cout << std::endl;
    }

}

LexicalAnalyser::~LexicalAnalyser(){
    for(int i = 0; i < this->tokens.size(); i++){
	delete this->tokens[i]; 
    }
}


// scan the source code
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
               
                if (util::isAlpha(ch)) {
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
                else if (util::isNumber(ch)) this->state = 12;
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

                if (util::isAlpha(ch) || util::isNumber(ch)) {
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
                else if (util::isNumber(ch)) this->state = 12;
                else {
                    this->state = 9999;
                    this->token_type = "op"; 
                }

                break;

            // automata state 5
            case 5:
                if (ch == '-' || ch == '=') this->state = 333;
                else if (util::isNumber(ch)) this->state = 12;
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
                if (util::isNumber(ch)) this->state = 12;
                else if(ch == '.') this->state = 122;
                else {
                    this->state = 9999;
                    this->token_type = "num";
                } 

                break;

            // automata state 122
            case 122:
                if (util::isNumber(ch)) this->state = 1222;
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
                if (util::isNumber(ch)) this->state = 1222; 
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
                str = util::createString(this->word_begin,
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
		   value = util::convertToNumber(str);
		}                
		else {
		    // find the str in token list
		    // if it was not there then put the token
		    // in the symbol table
		    value = TokenList::getTokenIndex(str);
		    if(value == -1){
			this->symbol_table.push_back(str);	 
			value = ++this->st_index;
		    }
		    else if(this->token_type == "id"){
			this->token_type = "kw";
		    }
		}

		token = new Token(value, this->token_type);

                this->tokens.push_back(token);
                this->word_begin = this->forward + 1;
                this->state = 0;


                break;

            // error state
            case -1: 
                str = util::createString(this->word_begin,
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

std::vector<Token*> LexicalAnalyser::getTokens(){
    return this->tokens; 
}



