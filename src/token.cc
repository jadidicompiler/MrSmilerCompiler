#include "token.h"
#include <string>

Token::Token(int value, std::string type){
    this->value = value;
    this->type = type;
}

int Token::getValue(){
    return this->value;
}

std::string Token::getType(){
    return this->type;
}


#define TOKEN(name, string) string,
std::string TokenList::token_names[NUM_TOKENS] = {
    TOKEN_LIST(TOKEN) 
};
#undef TOKEN

int TokenList::getTokenIndex(std::string token){
    for(int i = 0; i < NUM_TOKENS; i++){
	if (token.compare(token_names[i]) == 0){
	    return i;	
	}
    }
    return -1;
}
