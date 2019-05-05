
#ifndef TOKEN_H
#define TOKEN_H

#include <string>

// token list is a macro which contains all valid tokens
// in this example language
// every 'Token' it self is a macro
// which holds three value
// Token(tokenName, tokenString, tokenType)
#define TOKEN_LIST(TOKEN)                       \
						\
    /* binary operators */                      \
    TOKEN(ADD, "+")	                        \
    TOKEN(SUB, "-")	                        \
    TOKEN(MUL, "*")                             \
    TOKEN(DIV, "/")				\
    TOKEN(MOD, "%")                             \
    TOKEN(EXP, "**")                            \
    TOKEN(OR, "||")                             \
    TOKEN(AND, "&&")                            \
    TOKEN(BIT_OR, "|")                          \
    TOKEN(BIT_XOR, "^")                         \
    TOKEN(BIT_AND, "&")                         \
    TOKEN(SHL, "<<")                            \
    TOKEN(SAR, ">>")                            \
    TOKEN(CONDITIONAL, "?")                     \
                                                \
                                                \
    /* puctuator or seperators */               \
    TOKEN(LPAREN, "(")                          \
    TOKEN(RPAREN, ")")                          \
    TOKEN(LBRACK, "[")                          \
    TOKEN(RBRACK, "]")                          \
    TOKEN(LBRACE, "{")                          \
    TOKEN(RBRACE, "}")                          \
    TOKEN(COLON, ":")                           \
    TOKEN(SEMICOLON, ";")                       \
    TOKEN(PERIOD, ".")                          \
    TOKEN(INC, "++")                            \
    TOKEN(DEC, "--")                            \
    TOKEN(ARROW, "=>")                          \
                                                \
    /* assignment operators */                  \
    TOKEN(ASSIGN, "=")                          \
    TOKEN(ASSIGN_ADD, "+=")                     \
    TOKEN(ASSIGN_SUB, "-=")                     \
    TOKEN(ASSIGN_MUL, "*=")                     \
    TOKEN(ASSIGN_DIV, "/=")                     \
    TOKEN(ASSIGN_MOD, "%=")                     \
                                                \
    /* compare operators */                     \
    TOKEN(EQ, "==")                             \
    TOKEN(NE, "!=")                             \
    TOKEN(EQ_STRICT, "===")                     \
    TOKEN(NE_STRICT, "!==")                     \
    TOKEN(LT, "<")                              \
    TOKEN(GT, ">")                              \
    TOKEN(LTE, "<=")                            \
    TOKEN(GTE, ">=")                            \
                                                \
    /* unary operators */                       \
    TOKEN(NOT, "!")                             \
    TOKEN(BIT_NOT, "~")                         \
                                                \
    /* Keywords */                              \
    TOKEN(DELETE, "delete")                     \
    TOKEN(TYPEOF, "typeof")                     \
    TOKEN(VOID, "void")                         \
    TOKEN(BREAK, "break")                       \
    TOKEN(CASE, "case")                         \
    TOKEN(CATCH, "catch")                       \
    TOKEN(CONTINUE, "continue")                 \
    TOKEN(DEBUGGER, "debugger")                 \
    TOKEN(DEFAULT, "default")                   \
    TOKEN(DO, "do")                             \
    TOKEN(ELSE, "else")                         \
    TOKEN(FINALLY, "finally")                   \
    TOKEN(FOR, "for")                           \
    TOKEN(FUNCTION, "function")                 \
    TOKEN(IF, "if")                             \
    TOKEN(NEW, "new")                           \
    TOKEN(RETURN, "return")                     \
    TOKEN(SWITCH, "switch")                     \
    TOKEN(THIS, "this")                         \
    TOKEN(THROW, "throw")                       \
    TOKEN(TRY, "try")                           \
    TOKEN(VAR, "var")                           \
    TOKEN(WHILE, "while")                       \
    TOKEN(WITH, "with")                         \
    TOKEN(NULL_LITERAL, "null")                 \
    TOKEN(TRUE_LITERAL, "true")                 \
    TOKEN(FALSE_LITERAL, "false")               \
    TOKEN(ASYNC, "async")                       \
    TOKEN(AWAIT, "await")                       \
    TOKEN(CLASS, "class")                       \
    TOKEN(CONST, "const")                       \
    TOKEN(ENUM, "enum")                         \
    TOKEN(EXPORT, "export")                     \
    TOKEN(EXTENDS, "extends")                   \
    TOKEN(IMPORT, "import")                     \
    TOKEN(LET, "let")                           \
    TOKEN(YIELD, "yield")                       \
     

class TokenList {
    public:
	std::string getString();	

	#define TOKEN(name, string) name,
	enum {
	    TOKEN_LIST(TOKEN)
	    NUM_TOKENS
	};
	#undef TOKEN

	static int getTokenIndex(std::string);

    private:
	static std::string token_names[NUM_TOKENS];
	
};


class Token {
    
    public:
	Token(int, std::string);
	int getValue();
	std::string getType();
	
    private:
        int value;
	std::string type;
};

#endif // TOKEN_H

