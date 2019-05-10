#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include <vector>

#define ERRORS(ERROR)                                                     \
    ERROR(FUNCTIONID, "after function keyword there must be a identifier")\
    ERROR(MLPAREN, "missing '('")                                         \
    ERROR(MRPAREN, "missing ')'")                                         \
    ERROR(MLBRACE, "missing '{'")                                         \
    ERROR(MRBRACE, "missing '}'")                                         \
    ERROR(MSIMICOLON, "missing ';'")                                      \







// parser class responsible for
// validating source code via grammer
class Parser{
    public:
	Parser(std::vector<Token*> tokens);
	void parse();		
	
	#define ERROR(name, string) name,
	enum {
	    ERRORS(ERROR)
	    NUM_ERRORS
	};	
	#undef ERROR
    private:
		

	std::vector<Token*> tokens;

	// token handling
	Token* lookAhead;
	int token_index = -1;

	// put the next token in lookAhead
	void nextToken();

	// error handling
	static const char* errors[NUM_ERRORS];	
	std::vector<std::string> parser_errors;
	bool isError = false;
	inline void makeError(int errNum);
	const char* getError(int errNum);

	// grammer methods
	void ntProgram();
	void ntElement();
	void ntParameterListOpt();
	void ntParameterList();
	void ntStatements();
	void ntStatement();
	void ntCompoundStatement();

	void accept();
	void reject();


};


#endif // PARSER_H
