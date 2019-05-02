
#ifndef TOKEN_H
#define TOKEN_H



// token list is a macro which contains all valid tokens
// in this example language
// every 'Token' it self is a macro
// which holds three value
// Token(tokenName, tokenString, tokenType)
#define Token_list(Token) \
    
    /* binary operators*/
    Token(ADD, "+", "op")

// this class holds token information
// like <token_type, token_postion>
class Token{
    
    public:

	enum Name {
	    
	    TOKEN_LIST,
	    NUM_TOKENS
	}


        // constructor 1 string , int
        Token(std::string token_type, int token_value){
            this->token_type = token_type; 
            this->token_value = token_value; 
        }

        // constructor 2 strin , string
        Token(std::string token_type, std::string token_value_str){
            this->token_type = token_type; 
            this->token_value_str = token_value_str;
        }

        // void setTokenName(std::string name){this->token_name_ = name;}
        std::string getTokenType(){return this->token_type;}
        int getTokenValue(){return this->token_value;}
        std::string getTokenValueStr(){return this->token_value_str;}


    private:
        std::string token_type;
        std::string token_value_str;
        int token_value;

};

#endif // TOKEN_H


