
#ifndef TOKEN_H
#define TOKEN_H



// token list is a macro which contains all valid tokens
// in this example language
// every 'Token' it self is a macro
// which holds three value
// Token(tokenName, tokenString, tokenType)
#define TokenList(Token)                        \
						\
    /* binary operators*/                       \
    Token(ADD, "+")	                        \
    Token(SUB, "-")	                        \
    Token(MUL, "*")                             \
    Token(DIV, "/")				\
    Token(MOD, "%")                             \
    Token(EXP, "**")                            \
    Token(OR, "||")                             \    
    Token(AND, "&&")                            \
    Token(BIT_OR, "|")                          \
    Token(BIT_XOR, "^")                         \
    Token(BIT_AND, "&")                         \
    Token(SHL, "<<")                            \
    Token(SAR, ">>")                            \
    Token(CONDITIONAL, "?")                     \
                                                \
                                                \ 
    /* puctuator or seperators */               \
    Token(LPAREN, "(")                          \    
    Token(RPAREN, ")")                          \ 
    Token(LBRACK, "[")                          \ 
    Token(RBRACK, "]")                          \ 
    Token(LBRACE, "{")                          \ 
    Token(RBRACE, "}")                          \ 
    Token(COLON, ":")                           \
    Token(SEMICOLON, ";")                       \
    Token(PERIOD, ".")                          \
    Token(INC, "++")                            \ 
    Token(DEC, "--")                            \ 
    Token(ARROW, "=>")                          \ 
                                                \
    /* assignment operators */                  \
    Token(ASSIGN, "=")                          \
    Token(ASSIGN_ADD, "+=")                     \
    Token(ASSIGN_SUB, "-=")                     \
    Token(ASSIGN_MUL, "*=")                     \
    Token(ASSIGN_DIV, "/=")                     \
    Token(ASSIGN_MOD, "%=")                     \
                                                \
    /* compare operators */                     \
    Token(EQ, "==")                             \
    Token(NE, "!=")                             \
    Token(EQ_STRICT, "===")                     \
    Token(NE_STRICT, "!==")                     \
    Token(LT, "<")                              \
    Token(GT, ">")                              \
    Token(LTE, "<=")                            \
    Token(GTE, ">=")                            \
                                                \
    /* unary operators */                       \
    Token(NOT, "!")                             \
    Token(BIT_NOT, "~")                         \
                                                \
    /* Keywords */                              \
    Token(DELETE, "delete")                     \
    Token(TYPEOF, "typeof")                     \
    Token(VOID, "void")                         \
    Token(BREAK, "break")                       \
    Token(CASE, "case")                         \
    Token(CATCH, "catch")                       \
    Token(CONTINUE, "continue")                 \
    Token(DEBUGGER, "debugger")                 \
    Token(DEFAULT, "default")                   \
    Token(DO, "do")                             \
    Token(ELSE, "else")                         \
    Token(FINALLY, "finally")                   \
    Token(FOR, "for")                           \
    Token(FUNCTION, "function")                 \
    Token(IF, "if")                             \
    Token(NEW, "new")                           \
    Token(RETURN, "return")                     \
    Token(SWITCH, "switch")                     \
    Token(THIS, "this")                         \
    Token(THROW, "throw")                       \
    Token(TRY, "try")                           \
    Token(VAR, "var")                           \
    Token(WHILE, "while")                       \
    Token(WITH, "with")                         \
    Token(NULL_LITERAL, "null")                 \
    Token(TRUE_LITERAL, "true")                 \
    Token(FALSE_LITERAL, "false")               \
    Token(ASYNC, "async")                       \
    Token(AWAIT, "await")                       \
    Token(CLASS, "class")                       \
    Token(CONST, "const")                       \
    Token(ENUM, "enum")                         \
    Token(EXPORT, "export")                     \
    Token(EXTENDS, "extends")                   \
    Token(IMPORT, "import")                     \
    Token(LET, "let")                           \
    Token(YIELD, "yield")                       \
     

class Token{
    
    public:

        // void setTokenName(std::string name){this->token_name_ = name;}
        /* std::string getTokenType(){return this->token_type;} */
        /* int getTokenValue(){return this->token_value;} */
        /* std::string getTokenValueStr(){return this->token_value_str;} */


    private:
        int value;
	std::string type;
	

};



#endif // TOKEN_H

