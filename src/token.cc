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

bool Token::valueIs(int value){
    if (this->type.compare("id") && this->type.compare("num")){
	return (this->value == value);
    }
    return false;
}

bool Token::typeIs(char* str){
    return (this->type.compare(str) == 0? true: false );
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
std::string TokenList::getTokenString(int index){
    return token_names[index];
}
